

# potential mentors

SomeoneToIgnore


# inbox

history_items

# dev

```rust
use editor::{
    actions::ToggleOutline, scroll::Autoscroll, Anchor, AnchorRangeExt, Editor, EditorMode,
};
use fuzzy::StringMatch;
use gpui::{
    div, rems, AppContext, DismissEvent, EventEmitter, FocusHandle, FocusableView, ParentElement,
    Point, Render, Styled, Task, View, ViewContext, VisualContext, WeakView, WindowContext,
};
use language::Outline;
use ordered_float::OrderedFloat;
use picker::{Picker, PickerDelegate};
use std::{
    cmp::{self, Reverse},
    sync::Arc,
};

use theme::ActiveTheme;
use ui::{prelude::*, ListItem, ListItemSpacing};
use util::ResultExt;
use workspace::{DismissDecision, ModalView};

pub fn init(cx: &mut AppContext) {
    cx.observe_new_views(OutlineView::register).detach();
}

pub fn toggle(editor: View<Editor>, _: &ToggleOutline, cx: &mut WindowContext) {
    let outline = editor
        .read(cx)
        .buffer()
        .read(cx)
        .snapshot(cx)
        .outline(Some(cx.theme().syntax()));

    if let Some((workspace, outline)) = editor.read(cx).workspace().zip(outline) {
        workspace.update(cx, |workspace, cx| {
            workspace.toggle_modal(cx, |cx| OutlineView::new(outline, editor, cx));
        })
    }
}

pub struct OutlineView {
    picker: View<Picker<OutlineViewDelegate>>,
}

impl FocusableView for OutlineView {
    fn focus_handle(&self, cx: &AppContext) -> FocusHandle {
        self.picker.focus_handle(cx)
    }
}

impl EventEmitter<DismissEvent> for OutlineView {}
impl ModalView for OutlineView {
    fn on_before_dismiss(&mut self, cx: &mut ViewContext<Self>) -> DismissDecision {
        self.picker
            .update(cx, |picker, cx| picker.delegate.restore_active_editor(cx));
        DismissDecision::Dismiss(true)
    }
}

impl Render for OutlineView {
    fn render(&mut self, _cx: &mut ViewContext<Self>) -> impl IntoElement {
        v_flex().w(rems(34.)).child(self.picker.clone())
    }
}

impl OutlineView {
    fn register(editor: &mut Editor, cx: &mut ViewContext<Editor>) {
        if editor.mode() == EditorMode::Full {
            let handle = cx.view().downgrade();
            editor
                .register_action(move |action, cx| {
                    if let Some(editor) = handle.upgrade() {
                        toggle(editor, action, cx);
                    }
                })
                .detach();
        }
    }

    fn new(
        outline: Outline<Anchor>,
        editor: View<Editor>,
        cx: &mut ViewContext<Self>,
    ) -> OutlineView {
        let delegate = OutlineViewDelegate::new(cx.view().downgrade(), outline, editor, cx);
        let picker =
            cx.new_view(|cx| Picker::uniform_list(delegate, cx).max_height(Some(vh(0.75, cx))));
        OutlineView { picker }
    }
}

struct OutlineViewDelegate {
    outline_view: WeakView<OutlineView>,
    active_editor: View<Editor>,
    outline: Outline<Anchor>,
    selected_match_index: usize,
    prev_scroll_position: Option<Point<f32>>,
    matches: Vec<StringMatch>,
    last_query: String,
}

enum OutlineRowHighlights {}

impl OutlineViewDelegate {
    fn new(
        outline_view: WeakView<OutlineView>,
        outline: Outline<Anchor>,
        editor: View<Editor>,
        cx: &mut ViewContext<OutlineView>,
    ) -> Self {
        Self {
            outline_view,
            last_query: Default::default(),
            matches: Default::default(),
            selected_match_index: 0,
            prev_scroll_position: Some(editor.update(cx, |editor, cx| editor.scroll_position(cx))),
            active_editor: editor,
            outline,
        }
    }

    fn restore_active_editor(&mut self, cx: &mut WindowContext) {
        self.active_editor.update(cx, |editor, cx| {
            editor.clear_row_highlights::<OutlineRowHighlights>();
            if let Some(scroll_position) = self.prev_scroll_position {
                editor.set_scroll_position(scroll_position, cx);
            }
        })
    }

    fn set_selected_index(
        &mut self,
        ix: usize,
        navigate: bool,
        cx: &mut ViewContext<Picker<OutlineViewDelegate>>,
    ) {
        self.selected_match_index = ix;

        if navigate && !self.matches.is_empty() {
            let selected_match = &self.matches[self.selected_match_index];
            let outline_item = &self.outline.items[selected_match.candidate_id];

            self.active_editor.update(cx, |active_editor, cx| {
                active_editor.clear_row_highlights::<OutlineRowHighlights>();
                active_editor.highlight_rows::<OutlineRowHighlights>(
                    outline_item.range.start..outline_item.range.end,
                    cx.theme().colors().editor_highlighted_line_background,
                    true,
                    cx,
                );
                active_editor.request_autoscroll(Autoscroll::center(), cx);
            });
        }
    }
}

impl PickerDelegate for OutlineViewDelegate {
    type ListItem = ListItem;

    fn placeholder_text(&self, _cx: &mut WindowContext) -> Arc<str> {
        "Search buffer symbols...".into()
    }

    fn match_count(&self) -> usize {
        self.matches.len()
    }

    fn selected_index(&self) -> usize {
        self.selected_match_index
    }

    fn set_selected_index(&mut self, ix: usize, cx: &mut ViewContext<Picker<OutlineViewDelegate>>) {
        self.set_selected_index(ix, true, cx);
    }

    fn update_matches(
        &mut self,
        query: String,
        cx: &mut ViewContext<Picker<OutlineViewDelegate>>,
    ) -> Task<()> {
        let selected_index;
        if query.is_empty() {
            self.restore_active_editor(cx);
            self.matches = self
                .outline
                .items
                .iter()
                .enumerate()
                .map(|(index, _)| StringMatch {
                    candidate_id: index,
                    score: Default::default(),
                    positions: Default::default(),
                    string: Default::default(),
                })
                .collect();

            let editor = self.active_editor.read(cx);
            let cursor_offset = editor.selections.newest::<usize>(cx).head();
            let buffer = editor.buffer().read(cx).snapshot(cx);
            selected_index = self
                .outline
                .items
                .iter()
                .enumerate()
                .map(|(ix, item)| {
                    let range = item.range.to_offset(&buffer);
                    let distance_to_closest_endpoint = cmp::min(
                        (range.start as isize - cursor_offset as isize).abs(),
                        (range.end as isize - cursor_offset as isize).abs(),
                    );
                    let depth = if range.contains(&cursor_offset) {
                        Some(item.depth)
                    } else {
                        None
                    };
                    (ix, depth, distance_to_closest_endpoint)
                })
                .max_by_key(|(_, depth, distance)| (*depth, Reverse(*distance)))
                .map(|(ix, _, _)| ix)
                .unwrap_or(0);
        } else {
            self.matches = smol::block_on(
                self.outline
                    .search(&query, cx.background_executor().clone()),
            );
            selected_index = self
                .matches
                .iter()
                .enumerate()
                .max_by_key(|(_, m)| OrderedFloat(m.score))
                .map(|(ix, _)| ix)
                .unwrap_or(0);
        }
        self.last_query = query;
        self.set_selected_index(selected_index, !self.last_query.is_empty(), cx);
        Task::ready(())
    }

    fn confirm(&mut self, _: bool, cx: &mut ViewContext<Picker<OutlineViewDelegate>>) {
        self.prev_scroll_position.take();

        self.active_editor.update(cx, |active_editor, cx| {
            let highlight = active_editor
                .highlighted_rows::<OutlineRowHighlights>()
                .next();
            if let Some((rows, _)) = highlight {
                active_editor.change_selections(Some(Autoscroll::center()), cx, |s| {
                    s.select_ranges([rows.start..rows.start])
                });
                active_editor.clear_row_highlights::<OutlineRowHighlights>();
                active_editor.focus(cx);
            }
        });

        self.dismissed(cx);
    }

    fn dismissed(&mut self, cx: &mut ViewContext<Picker<OutlineViewDelegate>>) {
        self.outline_view
            .update(cx, |_, cx| cx.emit(DismissEvent))
            .log_err();
        self.restore_active_editor(cx);
    }

    fn render_match(
        &self,
        ix: usize,
        selected: bool,
        cx: &mut ViewContext<Picker<Self>>,
    ) -> Option<Self::ListItem> {
        let mat = self.matches.get(ix)?;
        let outline_item = self.outline.items.get(mat.candidate_id)?;

        Some(
            ListItem::new(ix)
                .inset(true)
                .spacing(ListItemSpacing::Sparse)
                .selected(selected)
                .child(
                    div()
                        .text_ui(cx)
                        .pl(rems(outline_item.depth as f32))
                        .child(language::render_item(outline_item, mat.ranges(), cx)),
                ),
        )
    }
}

```

sudo apt install libstdc++-12-dev

open_paths_with_positions



ToggleGoToLine


alacritty_terminal


# Conversations

## Zed Channels

Our Zed channel tree is public. You can find us hanging out and writing code across various channels. The root channel, [#zed](https://zed.dev/channel/zed-283), is a great place to ask questions and get to know other Zed users.

## Discord Channel

[Zed Community](https://discord.gg/zed-community) is our official Discord channel. We drop in pretty regularly to answer questions and chat with the community.

## Twitter

We use Twitter to highlight new Zed features and to share our blog posts. Follow us [@zeddotdev](https://x.com/zeddotdev).

## YouTube

We have a [YouTube channel](https://www.youtube.com/@zeddotdev) where we post longer-form videos about Zed.

## Blog

Our [blog](https://zed.dev/blog) gets frequent updates. We post about big releases, new features, and under-the-hood Zed tech.


# Data Structures

```rust
pub struct AppContext {
    pub(crate) this: Weak<AppCell>,
    pub(crate) platform: Rc<dyn Platform>, (gpui, ui, picker, remote, terminal, title_bar, vim)
    text_system: Arc<TextSystem>, (assets, editor, gpui, languages, markdown, repl, storybook, terminal, theme, zed)
    flushing_effects: bool,
    pending_updates: usize,
    pub(crate) actions: Rc<ActionRegistry>, (editor, gpui, project, remote_server, vim, workspace, zed)
    pub(crate) active_drag: Option<AnyDrag>, (gpui)
    pub(crate) background_executor: BackgroundExecutor, (assistant, auto_update, call, channel, client, collab, collab_ui, command_palette, context servers, copilot, db, editor, extenstion, feedback, file_finder, gpui, image_viewer, indexed_docs, journal, language, language_model, live_kit_client, lsp, markdown, multi_buffer, outline, outline_pannel, prettier, project, project_pannel, project_symbols, rencent_projects, remote, repl, search, semantic_index,session, settings, snippets_ui, storybook, supermaven, task, tasks_ui, terminal, terminal_view, theme_selector, ui, vcs_menu, vim, welcome, workspace, worktree, zed)
    pub(crate) foreground_executor: ForegroundExecutor, (assistant, call, collab, editor, extension, gpui, lsp, project, project_panel, remote, workspace, zed)
    pub(crate) loading_assets: FxHashMap<(TypeId, u64), Box<dyn Any>>, (gpui)
    asset_source: Arc<dyn AssetSource>, (assets, gpui, storybook, zed)
    pub(crate) svg_renderer: SvgRenderer, (gpui)
    http_client: Arc<dyn HttpClient>, (assistant, auto_update, client, collab, editor, extension, feedback, gpui, indexed_docs, language_model, lanuages, project, supermaven, zed)
    pub(crate) globals_by_type: FxHashMap<TypeId, Box<dyn Any>>, (gpui)
    pub(crate) entities: EntityMap, (client, gpui, remote, rpc)
    pub(crate) new_view_observers: SubscriberSet<TypeId, NewViewListener>, (gpui)
    pub(crate) windows: SlotMap<WindowId, Option<Window>>, (assisant, collab, command_palette, editor, gpui, recent_projects, workspace, zed)
    pub(crate) window_handles: FxHashMap<WindowId, AnyWindowHandle>, (gpui)
    pub(crate) keymap: Rc<RefCell<Keymap>>, (gpui)
    pub(crate) global_action_listeners: (gpui)
        FxHashMap<TypeId, Vec<Rc<dyn Fn(&dyn Any, DispatchPhase, &mut Self)>>>,
    pending_effects: VecDeque<Effect>, (gpui)
    pub(crate) pending_notifications: FxHashSet<EntityId>, (gpui)
    pub(crate) pending_global_notifications: FxHashSet<TypeId>,(gpui)
    pub(crate) observers: SubscriberSet<EntityId, Handler>,
    // TypeId is the type of the event that the listener callback expects
    pub(crate) event_listeners: SubscriberSet<EntityId, (TypeId, Listener)>, (gpui)
    pub(crate) keystroke_observers: SubscriberSet<(), KeystrokeObserver>, (gpui)
    pub(crate) release_listeners: SubscriberSet<EntityId, ReleaseListener>, (gpui)
    pub(crate) global_observers: SubscriberSet<TypeId, Handler>, (gpui)
    pub(crate) quit_observers: SubscriberSet<(), QuitHandler>, (gpui)
    pub(crate) layout_id_buffer: Vec<LayoutId>, // We recycle this memory across layout requests. (gpui)
    pub(crate) propagate_event: bool, (gpui)
    pub(crate) prompt_builder: Option<PromptBuilder>, (assitant, gpui)

    #[cfg(any(test, feature = "test-support", debug_assertions))]
    pub(crate) name: Option<&'static str>,
}
```