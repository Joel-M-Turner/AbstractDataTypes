/**
 * Implementation for a Queue ADT. Written by Joel Turner (z5689245),
 * from 11/08/2025 to 12/08/2025.
 * Implementation Details:
 * - Uses a linked list, with a wrapper struct containing both the list's
 *   head and tail for less intensive insertion and deletion
*/

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

//------------------------------Helper Functions------------------------------//

/**
 * Helper function for QueueNew which allocates memory for a queue 
 * and checks for malloc returning NULL
 * Worst-Case Time Complexity: O(1)
 */
static Queue initQueue();

// 
static struct queueNode *initQueueNode(Item item);

//-------------------------------Implementation-------------------------------//

/**
 * Creates a new, empty Queue 
 * Worst-Case Time Complexity: O(1)
*/
Queue QueueNew() {
    Queue Q = initQueue();
    *Q = (struct queue) {NULL, NULL, 0};
    return Q;
}

/**
 * Helper function for QueueNew which allocates memory for a queue 
 * and checks for malloc returning NULL
 * Worst-Case Time Complexity: O(1)
 */
static Queue initQueue() {
    Queue Q = malloc(sizeof(struct queue));
    if (Q == NULL) {
        fprintf(stderr, "error: out of memory");
    }
    return Q;
}

/**
 * Adds an item to the end of a Queue
 * Worst-Case Time Complexity: O(1)
 */
void QueueEnqueue(Queue Q, Item item) {
    struct queueNode *newNode = initQueueNode(item);
    *newNode = (struct queueNode) {item, NULL, Q->tail};
    if (Q->size == 0) {
        Q->head = newNode;
    } else {
        Q->tail->next = newNode;
    }
    Q->tail = newNode;
    Q->size++;
    return;
}


static struct queueNode *initQueueNode(Item item) {
    struct queueNode *newNode = malloc(sizeof(struct queueNode));
    if (newNode == NULL) {
        fprintf(stderr, "error: out of memory");
        exit(EXIT_FAILURE);
    }
    return newNode;
}

/**
 * Removes and returns the item from the front of a Queue
 * Assumes the given Queue is not empty
 * Worst-Case Time Complexity: O(1)
 */
Item QueueDequeue(Queue Q) {
    if (Q->size == 0) {
        fprintf(stderr, "error: queue is empty!");
        exit(EXIT_FAILURE);
    }
    Item item = Q->head->val;
    struct queueNode *newHead = Q->head->next;
    free(Q->head);
    Q->head = newHead;
    if (Q->size == 1) {
        Q->tail = NULL;
    }
    Q->size--;
    return item;
};

/**
 * Returns item at the front of a Queue without removing it
 * Assumes the given Queue is not empty
 * Worst-Case Time Complexity: O(1)
 */
Item QueuePeek(Queue Q) {
    if (Q->size == 0) {
        fprintf(stderr, "error: queue is empty!");
        exit(EXIT_FAILURE);
    }
    return Q->head->val;
}

/**
 * Returns the number of items in a Queue
 * Worst-Case Time Complexity: O(1)
 */
int QueueSize(Queue Q) {
    return Q->size;
}

/**
 * Returns true if the given Queue is empty, and false if not
 * Worst-Case Time Complexity: O(1)
 */
bool QueueIsEmpty(Queue Q) {
    if (Q->size == 0) {
        return true;
    }
    return false;
}

/**
 * Frees all memory allocated to a Queue
 * Worst-Case Time Complexity: O(n)
 */
void QueueFree(Queue Q) {
    struct queueNode *curr = Q->head;
    while (curr != NULL) {
        struct queueNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(Q);
    return;
}

/**
 * Prints a Queue to stdout
 * Worst-Case Time Complexity: O(n)
 */
void QueuePrint(Queue Q) {
   printf("Queue: ");
    for (struct queueNode *curr = Q->head; curr != NULL; curr = curr->next) {
        printf(" %d", curr->val);
        if (curr->next != NULL) {
            printf(", ");
        }
    }
    printf("\n");
    return;
}