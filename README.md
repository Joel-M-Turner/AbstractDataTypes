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