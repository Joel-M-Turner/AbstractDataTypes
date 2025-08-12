# Abstract Data Types
Interface and Implemtation of Several Useful ADTs in c
## Stack
### Overview
A stack is a collection of items such that that last item to enter is the first to leave (LIFO - Last in First Out). Some examples of this are:
- Web Browser History
- Text editor undo/redo
- Function calls
- Balanced brackets ({()}())

Stacks support the following operations:
- Push - add a new item to the top of the stack
- Pop - remove the topmost item from the stack
- Size - return the number of items in the stack
- Peek - get the topmost item on the stack without removing it

### How to implement a stack?
Arrays and linked lists can both efficiently implement a stack.

## Queue
### Overview
A queue is a collection of items such that the first item to enter it the first to leave (FIFO - First in First out). Some examples of this are:
- Waiting lists
- Call centres
- Access to shared resources
- Processes in a computer

Queues support the following operations:
- Enqueue: Add an item to the end of the queue
- Dequeue: Remove the item at the front of the queue
- Size: Return the number of items in the queue
- Peek: Get the front-most item of the queue, without removing it 

### How to implement a queue?
It is easier to use a linked list than an array to implement a queue.

Using a linked list, use a wrapper struct to contain the tail struct so it can be manipulated easily. Worst-Case Time complexity is O(1) for Insertion, Deletion, Allocating, and Getting Size, and O(n) for freeing and printing

Using an array, keep track of the index of the 'front' of the queue, and when you dequeue the queue, you just move the front index along by one, and treat the data stored before the front index as junk. If you run out of allocated space in the array, looping around back to the junk data slots is allowed.

## Binary Search Tree
## Graph
### Overview
A graph is a series of nodes which are each connected to an arbitrary number of nodes. It is a more general data structure than linked lists and trees. Graphs are useful for maps, websites, social networks, circuits, networking, game states, and so on.

A graph contains:
- A set of V vertices (also called nodes)
- A set of E edges between pairs of vertices.

Vertices are usually distinguished by a unique identifier (usually between 0 and V -1).

Edges can be (but aren't always) directed, weighted and/or labelled

### Terminology
#### Graph Terminology
Graphs can be:
- **Undirected** or **Directed** (Do edges have direction?)
- **Unweighted** or **Weighted** (Do edges have an associated scalar?)
- **Without loops** or **with loops** (Can an edge start and end at the same vertex?)
- **Non-multigraph** or **multigraph** (Can multiple edges connect a single pair of nodes?)
- **Connected** or **Disconnected** (Can the graph be separated into multiple parts)

A **simple** graph is a type of graph which is:
- Undirected
- Without loops
- Non-multigraph

A **complete graph** is a graph where every vertex is connected to every other vertex via an edge. In a complete graph, E = `V(V-1)/2`

#### Vertex Terminology:
- **Adjacent** vertices have an edge connecting them
- If an edge `e` connects two vertices `v` and `w`, it is **incident** upon them 
- The **degree** of a vertex is the number of edges which are incident on it.
#### Sparsity:
The E:V ratio of a graph tells us about its sparsity:
- If E is close to V^2, the graph is **dense**
- If E is close to V, the graph is **sparse**
#### Paths
A path is a sequence of vertices connected by edges.

- A **simple** path has no repeating vertices
- A **cycle** is a type of path where only the first and last vertices are the same
### Graph Properties
- A **tree** is a connected graph with no cycles
- A **subgraph** of a graph G is a graph which contains a subset of the vertices of G and a subset of the edges between these vertices
- A **connected component** is a maximally connected subgraph
- A **spanning tree** of a graph G is a subgraph which contains all vertices of G and a single tree
- A **spanning forest** of a graph G is a subgraph containing all vertices of G and a single tree for each connected component
- A **clique** is a complete subgraph

### Implementation
There are three common implementation methods of a Graph ADT:
- **Adjacency Matrix**: Two-dimensional array of bools or ints indicating the presence of, and weight of adjacent nodes of each node.
- **Adjacency List**: Array of linked lists containing the adjacent nodes of each node
- **Array of Adjacent Pairs**: Array, where every entry contains two nodes (and a weight) indicating the edge between these nodes.

**Breadth First Search/Traversal**
-

**Depth First Search/Traversal**


### Traversal

There are two main types of graph traversal:
- **Breadth-First-Search**:
	-  Finds the shortest path in terms of nodes from any node to another node.
	- Searches nodes sequentially
	- Uses a Queue ADT to keep track of which nodes to explore (and the order)
- **Depth-First-Search**:
	 - Finds a path from any node to another node
	- Searches paths sequentially
	- Uses a Stack ADT to keep track of which nodes to explore (and the order)
	
The pseudocode for each implementation method is the same.
#### Breadth-First-Search (BFS)
Breadth-First-Search visits vertices in order of distance from the starting vertex in terms of the number of edges. It is implemented iteratively using a Queue ADT.
##### Pseudocode:
    bfs(G, src)
        Input: graph G, starting vertex src

        create visited array, initialised to false
        create predecessor array, initialised to -1
        create queue Q

        visited[src] = true;
        enqueue src into Q

        while Q is not empty
            v = dequeue from Q
            for each neighbour w of v in G such that visited[w] = false
                visited[w] = true
                predecessor[w] = v
                enqueue w into Q
##### Analysis

The time complexity of BFS depends on the graph implementation used:
- For the adjacency list representation, is it O(V + E) since:
    - Queue implementation has O(1) create, enqueue and dequeue, and O(V) or O(1) clear
    - Each vertex is visited at most once -> O(V)
    - For each vertex, all edges are considered once -> O(E)
     
#### BFS Path Finding
BFS finds the shortest path between the starting vertex and all other vertices in terms of the number of edges. By tracing through the predecessor array starting from `dest`, the shortest path from `dest` to `src` can be found. A stack can be used in conjunction with this method to find the path from `src` to `dest`.
##### Pseudocode
    bfsPathFind(G, src, dest):    
        Input: graph G, vertices src and dest

        ... BFS starting from src ...

        if predeessor[dest] != -1
            v = dest
            while v != src
                print v, "<-"
                v = predecessor[v]

            print src

#### Depth-First-Search
Depth First Search goes as far down one path as possible until it reaches a dead end, then backtracks until it funds a new path to take, and repeats.

DFS can be implemented iteratively using a stack, or recursively.

##### Pseudocode - Iterative Implementation
    dfs(G, src):
        Input: graph G, vertex src

        create visited array, initialised to false
        create predecessor array, initialised to -1
        create stack S

        push src onto S

        while S is not empty:
            v = pop from S
            if visited[v] = true:
                continue
            
            visited[v] = true

            for each neighbour w of v in G where visited[w] = false:
                predecessor[w] = v
                push w onto S

##### Pseudocode - Recursive Implementation
    dfs(G, src):    
        Input: graph G, starting vertex src

        create visited array, initialised to false
        dfsRec(G, src, visited)

    dfsRec(G, v, visited):
        Input: Graph G, vertex v, visited array

        visited[v] = true
        for each neighbour w of v in G:
            if visited[w] = false:
                dfsRec(G, v, visited)

##### Analysis
Recursive and Iterative DFS are both O(V + E) when using the adjacency list representation:
- Recursive DFS:
    - Each vertex is visited at most once -> O(V)
        - Function is called on each vertex at most once
    - For each vertex, all of its edges are considered once -> O(E)
- Iterative DFS:
    - Typical stack implementation has O(1) push and pop
    - Each vertex visited at most once -> O(V)
    - For each vertex, all of its edges are considered -> O(E)
#### DFS Path Checking
- Depth First Search is helpful for checking if a path is present, especially when the nodes being checked are far away from each other. 
##### Pseudocode
    dfsHasPath(G, src, dest)
        Input: graph G, vertices src and dest
        Output: true is there is a path from src to dest
                false otherwise
        
        create visited array, initialised to false
        return dfsHasPathRec(G, src, dest, visited)
    
    dfsHasPathRec(G, v, dest, visited)
        Input: graph G, vertices v and dest, visited array

        visited[v] = true
        if v = dest:
            return true

        for each neighbour w of v in G:
            if visited[w] = false:
                if dfsHasPathRec(G, w, dest, visited);
                    return true
        
        return false

#### DFS Path Finding
##### PseudoCode
    dfsFindPath(G, src, dest)
        InputL graph G, vertices src and dest

        create predecessor array, initialised to -1
        predecessor[src] = src

        if dfsFindRathRec(G, src, dest, predecessor):
            v = dest
            while v != src:
                print v, "<-"
                v = predecessor[v]

            print src
    
    dfsFindPathRec(G, v, dest, predecessor);
        if v = dest:
            return true
        
        for each neighbour w of v in G:
            if predecessor[w] = -1:
                -redecessor[w] = v
                if dfsFindPathRec(G, w, dest, predecessor):
                    return true

        return false

## Hash
## Priority Queue
### Overview
- A Priority Queue is an abstract data type (or a data structure) which are 
similar to queues, but each item has an associated priority, and the dequeued 
item is always the one with the highest priority, regardless of Enqueue order.
**Examples and Applications**
- Hospital Waiting Rooms
- Incident Management
- Huffman Coding
- Dijkstra's Algorithm
- Prim's Algorithm

A priority queue supports the following main operations:
- `Insert` - Insert an item with an associated priority.
- `Delete` - Delete (and return) the item with the highest priority.
- `Peek` - Get the item with the highest priority without deleting it.
- `IsEmpty`- Check if the priority queue is empty.

Depending on the implementation, either large or small priority may be taken to mean 'high priority'

### Worst-Case Time Complexities using different implementations
- Unordered Array:
    - Insertion: O(1)
    - Deletion: O(n)
    - Peek: O(n)
    - IsEmpty: O(1)
- Ordered Array:
    - Insertion: O(n)
    - Deletion: O(1)
    - Peek: O(1)
    - IsEmpty: O(1)
- Unordered Linked List:
    - Insertion: O(1)
    - Deletion: O(n)
    - Peek: O(n)
    - IsEmpty: O(1)
- Ordered Linked List:
    - Insertion: O(n)
    - Deletion: O(1)
    - Peek: O(1)
    - IsEmpty: O(1)

We can use a [heap](#heap) data structure to escape this O(n) time complexity. This results in a worst-case time complexity of O(log(n)) for insertion and deletion, and Peek and IsEmpty remain at O(1).
## Heap
### Overview
- A heap is a tree-based data structure which satisfies the <font style="color:lime">heap property</font>.
- The <font style="color:lime">Heap Property</font> details how the heap's data is ordered, and depends on the type of heap:
    - <font style="color:yellow">Max Heap</font> store numbers large to small top down. This means that the value in each node is greater than or equal to the values of its children.
    - <font style="color:yellow">Min Heap</font> store numbers small to large top down. This means that the value in each node is smaller than or equal to the values of its children.
- The <font style="color:lime">Completeness Property</font> is the requirement that all levels of the tree are fully filled, and the lowest level of the tree is filled from left to right.
- A heap effectively works as a [priority queue](#priority-queue)
### Binary Heaps
There are many variants of heaps. In this course (COMP2521) we will only consider <font style="color:yellow">Binary Heap</font>. This is a binary tree that follows the heap property (max/min heap) and the completeness property.

```
          13            |         13
         /  \           |        /  \
        /    \          |       /    \
       7      9         |      7      9
      / \    /          |     /      / \
     5   4  2           |    5      2   8
satisfies heap property |satisfies heap property
satisfies completeness  |does not satisfy completeness
 => is a binary heap    | => is not a binary heap
```

The completeness property means that a heap will always have $\lfloor log_2(n)\rfloor + 1$ levels, where n is the number of items in the heap.

### Implementation Details
Heaps are usually implemented using an array, where,
- The `0th` element is not used
- The `nth` level starts at the array's `2nth` index
- Array is in order of the tree's level order traversal. This implies the following useful property:
    - For an item at index `i`:
        - Its left child is located at index `2i`
        - Its right child is located at index `2i + 1`
        - Its parent is located at index `floor(i/2)` 
        (note that integer division in c automatically floors)

This makes it efficient to move up and down the tree, and makes traversal $log(n)$. Note that although resizing is O(n) in the worst-case, this is not counted since the initial size of the heap can be changed according to requirement, and 'worst-case' means worst possible input order, not worst-possible input size.

The binary heap above has the array
```
index:  0   1    2   3   4   5   6   7 
data: |   | 13 | 7 | 9 | 5 | 4 | 2 |   |...
```

- **Insertion**
	1. Add the new item into the last spot into heap
	2. While this item is not the root, and greater than its parent, swap it with its parent (Fix Up/Sift Up)
	3. Add one to the size
- **Deletion**
	1. Switch the root element with the final element in the heap
	2. While the new root is greater than either of its children, swap it with the greater of the two
	3. Decrease the size by one
	4. Return the old root
	The worst-case time complexity of this method is $O(log(N))$