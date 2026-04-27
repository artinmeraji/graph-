# Dijkstra's Algorithm: The Problem with Negative Weights

## Objective
The goal of this task is to explain why Dijkstra's algorithm doesn't work correctly when a graph has negative edge weights.

## Why it Fails
Dijkstra's algorithm is a "greedy" algorithm. This means that once it picks a node and decides it has found the shortest path to that node, it marks it as "visited" and never looks at it again. This works perfectly for positive weights, but negative weights can break this logic.

### Example Scenario
Let's look at a simple graph with 3 nodes: **A**, **B**, and **C**.

**The Edges:**
1. A -> B (Weight: 3)
2. A -> C (Weight: 5)
3. B -> C (Weight: -4)

**How Dijkstra's processes this:**
1. **Start at Node A**:
   - The distance to **B** is 3.
   - The distance to **C** is 5.
2. **Pick the Smallest Distance**:
   - The algorithm looks at 3 and 5. Since 3 is smaller, it picks **Node B**.
   - It marks **B** as "visited" and assumes the shortest path to B is 3.
3. **Pick the Next Smallest**:
   - The only node left is **C**. Its current distance is 5.
   - The algorithm marks **C** as "visited" and assumes the shortest path to C is 5.

**The Problem:**
If we actually follow the path **A -> B -> C**, the total weight is `3 + (-4) = -1`. 
- Our actual shortest path to C is **-1**.
- But Dijkstra's algorithm told us it was **5**.

Because Dijkstra's already "finished" with Node C when it saw the weight of 5, it never goes back to check if the negative weight at B could have made the path to C even shorter. It assumes that adding more edges will always make the path longer, which isn't true when negative numbers are involved!

## Conclusion
Dijkstra fails because it doesn't account for the possibility that a path that looks "expensive" early on (like going through B) might actually become "cheaper" later due to a negative edge. To solve this, you'd usually have to use something like the Bellman-Ford algorithm instead.
