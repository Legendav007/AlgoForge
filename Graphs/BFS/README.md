### Breadth-First Search (BFS)

It is a way to traverse a tree or graph by visiting things **in the order they are discovered**, not by going as deep as possible.

Essentially, processing what you know now, and remember what you need to do later.

### Analogy

We can think of BFS as a to-do list:

1. We start with one task: the root node.
2. We do the first task.
3. While doing it, we discover new tasks (its children).
4. We add those new tasks to the end of the list.
5. We move on to the next task in the list.

BFS relies on a **queue**, which behaves like a line at a counter:
Nodes are added to the back when they are discovered and are processed from the front one at a time.

### What BFS is actually doing

At any moment:

1. The queue contains nodes that are **discovered but not yet processed**
2. A pointer (or index) tells you **which node to process next**
3. Each iteration:
    - Processes exactly one node
    - Appends its children as future work

BFS ends when every discovered node has been processed.

> [!IMPORTANT]  
> For a better visual explanation check out [HelloInterview's articles on BFS](https://www.hellointerview.com/learn/code/breadth-first-search/introduction).