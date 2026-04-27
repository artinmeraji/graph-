# Graph Algorithms Assignment: BFS and DFS

## Task 1: Theoretical Graph
For this assignment, I designed a simple directed graph to show how BFS and DFS traverse through nodes. It has 6 nodes (A to F) and follows a tree-like structure which makes it easy to follow.

**Graph Diagram:**
```
      ( A )
      /   \
    (B)   (C)
    / \     \
  (D) (E)   (F)
```

**Connections:**
- A connects to B and C
- B connects to D and E
- C connects to F
- D, E, and F are leaf nodes (no outgoing edges)

---

## Task 2: C++ Implementation
I implemented the graph above using an adjacency list (with `std::map` and `std::vector`). For DFS, I used recursion because it's simpler to write, and for BFS, I used a queue to keep track of which level to visit next.

**Note:** You can find the full code implementation in the `main.cpp` file in this folder.

---

## Task 3: Comparison of BFS and DFS (Big O)

When looking at Big O notation, both Breadth-First Search (BFS) and Depth-First Search (DFS) actually have the same time complexity: **O(V + E)**.

Here is why:
- **V** stands for the number of vertices (nodes). In both algorithms, we visit every node exactly once because we keep track of "visited" nodes.
- **E** stands for the number of edges. For every node we visit, we look at all its neighbors (the edges connecting it). So, in total, we look at every edge in the graph.

Even though they have the same Big O time, they behave differently:
- **DFS** is better if you need to go deep into a path quickly or if you are using it for things like topological sorting. It uses less memory if the graph is very wide but not very deep (since it only stores the current path in the recursion stack).
- **BFS** is better for finding the shortest path in an unweighted graph because it explores all nodes at the current distance before moving further away. However, it can use more memory because the queue might have to store many nodes at once if the graph is very wide.

Overall, they are both efficient for searching graphs, just in different ways!
