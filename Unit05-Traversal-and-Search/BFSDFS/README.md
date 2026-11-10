# BFS and DFS
**Divya Sharma - IC-2K23-29**
## Problem Statement
Implement breadth first search and depth first search on a graph and compare the visit order.
## Algorithm
BFS uses a queue. Start at source, enqueue it, then repeatedly dequeue a node, print it, and enqueue its unvisited neighbours. This visits nodes level by level.
DFS uses a stack. Start at source, push it, then repeatedly pop a node, skip if already visited, print it, and push its unvisited neighbours. This goes as deep as possible before backtracking.
The graph is stored as an adjacency matrix because it has only 5 nodes, and the matrix is easier to index than a list in C.
## Pseudocode
```
BFS(start):
    queue = [start]
    visited[start] = true
    while queue not empty:
        node = dequeue()
        print node
        for each neighbour of node:
            if not visited[neighbour]:
                visited[neighbour] = true
                enqueue(neighbour)
DFS(start):
    stack = [start]
    while stack not empty:
        node = pop()
        if visited[node]: continue
        visited[node] = true
        print node
        for each neighbour of node in reverse:
            if not visited[neighbour]:
                push(neighbour)
```
## Complexity
Both are O(V + E) time and O(V) space for the visited array and the queue or stack. With an adjacency matrix the neighbour scan itself is O(V) per node, so the total becomes O(V²), which is fine for this graph size but would be slow for a large sparse graph.
## Sample Input / Output
```
Graph:  A-B  A-C  B-D  C-D  D-E
BFS from A: A B C D E
DFS from A: A B D E C
```
