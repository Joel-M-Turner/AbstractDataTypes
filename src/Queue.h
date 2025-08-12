/**
 * Interface for a Queue ADT. Written by Joel Turner (z5689245),
 * on 02/08/2025
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

// Change as required
typedef int Item;

typedef struct queue {
    struct queueNode *head;
    struct queueNode *tail;
    int size;
} *Queue;

struct queueNode {
    Item val;
    struct queueNode *next;
    struct queueNode *prev;
};

/**
 * Creates a new, empty Queue 
 * Worst-Case Time Complexity: O(1)
*/
Queue QueueNew();

/**
 * Adds an item to the end of a Queue
 * Worst-Case Time Complexity: O(1)
 */
void QueueEnqueue(Queue Q, Item item);

/**
 * Removes and returns the item from the front of a Queue
 * Assumes the given Queue is not empty
 * Worst-Case Time Complexity: O(1)
 */
Item QueueDequeue(Queue Q);

/**
 * Returns item at the front of a Queue without removing it
 * Assumes the given Queue is not empty
 * Worst-Case Time Complexity: O(1)
 */
Item QueuePeek(Queue Q);

/**
 * Returns the number of items in a Queue
 * Worst-Case Time Complexity: O(1)
 */
int QueueSize(Queue Q);

/**
 * Returns true if the given Queue is empty, and false if not
 * Worst-Case Time Complexity: O(1)
 */
bool QueueIsEmpty(Queue Q);

/**
 * Frees all memory allocated to a Queue
 * Worst-Case Time Complexity: O(n)
 */
void QueueFree(Queue Q);

/**
 * Prints a Queue to stdout
 * Worst-Case Time Complexity: O(n)
 */
void QueuePrint(Queue Q);

#endif