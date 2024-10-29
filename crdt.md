


# y-crdt

# eg walker

```ts
{ type: 'ins', pos: 0, content: 'A' },
```

```ts
enum ItemState {
  NotYetInserted = -1,
  Inserted = 0,
  Deleted = 1, // Or some +ive number of times the item has been deleted.
}

// This is internal only, and used while reconstructing the changes.
interface Item {
  opId: number,

  /**
   * The item's state at this point in the merge. This is initially set to Inserted,
   * but if we reverse the operation out we'll end up in NotYetInserted. And if the item
   * is deleted multiple times (by multiple concurrent users), we'll end up storing the
   * number of times the item was deleted here.
   */
  curState: ItemState,

  /**
   * The item's state when *EVERYTHING* has been merged. This is always either Inserted or Deleted.
   */
  endState: ItemState,

  // -1 means start / end of document. This is the core list CRDT (sync9/fugue).
  originLeft: number | -1,

  // -1 means the end of the document. This uses fugue's semantics.
  // All right children have a rightParent of -1.
  rightParent: number | -1,
}
```

```ts

interface Doc {
  oplog: ListOpLog<number>,
  content: number[],

  // And to make sure our behaviour matches actual fugue, run the same operations with
  // the reference fugue implementation to make sure the output is the same.
  fugue: ListFugueSimple<number> | null
}

```

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
type CGEntry = {
  version: LV,
  vEnd: LV, // > version.

  agent: string,
  seq: number, // Seq for version.

  parents: LV[] // Parents for version
}

type ClientEntry = {
  seq: number,
  seqEnd: number,
  /** LV of the first item in this run */
  version: LV,
}

export interface CausalGraph {
  /** Current global version frontier */
  heads: LV[],

  /** Map from localversion -> rawversion */
  entries: CGEntry[],

  /** Map from agent -> list of versions by that agent */
  agentToVersion: {[k: string]: ClientEntry[]},
}
```