/**
 * Interface for a Priority Queue ADT. Written by Joel Turner (z5689245),
 * from 02/08/2025 to 03/08/2025
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 15
#define REALLOCATION_FACTOR 2

// Change as required
typedef int Item;

typedef struct priorityQueue {
    struct pQItem *items;
    int numItems;
    int capacity;
} *PriorityQueue;

struct pQItem {
    Item item;
    int priority;
};

/**
 * Creates and allocates memory for an empty Priority Queue
 * Worse-Case Time Complexity: O(1)
 */
PriorityQueue PriorityQueueNew(void);

/** 
 * Frees all memory related to a Priority Queue
 * Worse-Case Time Complexity: O(1)
 */
void PriorityQueueFree(PriorityQueue priorityQueue);

/**
 * Adds an item to the Priority Queue with a priority
 * Worse-Case Time Complexity: O(log(n))
 */
void PriorityQueueInsert(
    PriorityQueue priorityQueue,
    Item item,
    int priority
);

/**
 * Deletes and returns the item with highest priority
 * Worst-Case Time Complexity: O(log(n))
 */
Item PriorityQueueDelete(PriorityQueue priorityQueue);

/**
 * Returns the item with highest priority
 * Worse-Case Time Complexity: O(1)
 */
Item PriorityQueuePeek(PriorityQueue priorityQueue);

/**
 * Checks whether the Priority Queue is empty, and returns the result
 * Worse-Case Time Complexity: O(1)
 */
bool PriorityQueueIsEmpty(PriorityQueue priorityQueue);

/**
 * Returns the number of items in the Priority Queue
 * Worse-Case Time Complexity: O(1)
 */
int PriorityQueueSize(PriorityQueue pQ);

/**
 * Prints the Priority Queue to stdout
 * Worst-Case Time Complexity: O(n)
 */
void PriorityQueuePrint(PriorityQueue pQ);

#endif