

# eg walker

```ts
interface EditContext {
  /**
   * All the items in document order. This list is grow-only, and will be spliced()
   * in as needed.
   */
  items: Item[],

  /**
   * When we delete something, we store the LV of the item that was deleted. This is
   * used when items are un-deleted (and re-deleted).
   * delTarget[del_lv] = target_lv.
   */
  delTargets: number[],

  /**
   * This is the same set of items as above, but this time indexed by LV. This is
   * used to make it fast & easy to activate and deactivate items.
   */
  itemsByLV: Item[],

  /**
   * Items in the EditContext have 2 version tags - curState and endState. These
   * store the state at 2 different versions while we traverse the operations.
   *
   * This parameter stores the current version itself.
   */
  curVersion: number[],
}

```


```ts

/** Local version */
export type LV = number

/** Local version range. Range is [start, end). */
export type LVRange = [start: number, end: number]
```



```ts
export interface CausalGraph {
  /** Current global version frontier */
  heads: LV[],

  /** Map from localversion -> rawversion */
  entries: CGEntry[],

  /** Map from agent -> list of versions by that agent */
  agentToVersion: {[k: string]: ClientEntry[]},
}
```