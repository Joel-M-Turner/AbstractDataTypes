/**
 * Implementation for a Priority Queue ADT. Written by Joel Turner (z5689245),
 * from 02/08/2025 to 03/08/2025
 * Implementation Details:
 * - Uses Heap ADT for Implementation (max heap)
 * - Interprets Higher Numbers as Higher Priority
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "PriorityQueue.h"

#define PQ_ROOT 1

//------------------------------Helper Functions------------------------------//

/**
 * Helper function for PriorityQueueInsert. Increases the size of the Priority
 * Queue. Worst-Case Time Complexity: O(n)
 */
static void resizePQ(PriorityQueue pQ);

/**
 * Helper function for PriorityQueueInsert. Heaps PQ after Insertion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixUp(struct pQItem items[], int i);

/**
 * Helper function for PriorityQueueDelete. Heaps PQ after Deletion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixDown(struct pQItem items[], int i, int numItems);

//-------------------------------Implementation-------------------------------//

/**
 * Creates and allocates memory for an empty Priority Queue
 * Worse-Case Time Complexity: O(1)
 */
PriorityQueue PriorityQueueNew(void) {
    PriorityQueue pQ = malloc(sizeof(*pQ));
    // Checks if Priority Queue allocation succeeded
    if (pQ == NULL) {
        fprintf(stderr, "error: Unable to allocate Priority Queue");
        exit(EXIT_FAILURE);
    }

    // Initialising Priority Queue's Fields
    pQ->numItems = 0;
    pQ->capacity = INITIAL_CAPACITY;
    pQ->items = malloc((pQ->capacity + 1) * sizeof(struct pQItem));

    // Checks if item allocation succeeded
    if (pQ->items == NULL) {
        fprintf(stderr, "error: Unable to allocate Priority Queue");
        exit(EXIT_FAILURE);
    }
    return pQ;
}   

/** 
 * Frees all memory related to a Priority Queue
 * Worse-Case Time Complexity: O(1)
 */
void PriorityQueueFree(PriorityQueue priorityQueue) {
    free(priorityQueue->items);
    free(priorityQueue);
    return;
}

/**
 * Adds an item to the Priority Queue with a priority
 * Worse-Case Time Complexity: O(log(n))
 */
void PriorityQueueInsert(
    PriorityQueue pQ,
    Item item,
    int priority
) {
    // Resizes if the heap is full
    if (pQ->numItems == pQ->capacity) {
        resizePQ(pQ);
    }

    pQ->numItems++;
    pQ->items[pQ->numItems] = (struct pQItem) {item, priority};
    fixUp(pQ->items, pQ->numItems);

    return;   
}

/**
 * Helper function for PriorityQueueInsert. Increases the size of the Priority
 * Queue by a factor defined in PriorityQueue.h (REALLOCATION_FACTOR).
 * Worst-Case Time Complexity: O(n)
 */
static void resizePQ(PriorityQueue pQ) {
    pQ->capacity *= REALLOCATION_FACTOR;
    pQ->items = realloc(
        pQ->items, 
        (pQ->capacity + 1) * (sizeof(struct pQItem))
    );  
    
    // Error if no memory left
    if (pQ->items == NULL) {
        fprintf(stderr, "error: unable to reallocate heap\n");
        exit(EXIT_FAILURE);
    }
    return;
}

/**
 * Helper function for PriorityQueueInsert. Heaps PQ after Insertion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixUp(struct pQItem items[], int i) {
    while ((i > PQ_ROOT) && (items[i].priority > items[i / 2].priority)) {
        // Swap items[i] and items[i/2]
        struct pQItem temp = items[i/2];
        items[i/2] = items[i];
        items[i] = temp;
        i = i / 2;
    }
    return;
}

/**
 * Deletes and returns the item with highest priority
 * Worst-Case Time Complexity: O(log(n))
 */
Item PriorityQueueDelete(PriorityQueue pQ) {
    if (pQ->numItems == 0) {
        fprintf(stderr, "error: cannot delete from empty priority queue");
        exit(EXIT_FAILURE);
    }
    Item item = pQ->items[PQ_ROOT].item;
    pQ->items[PQ_ROOT] = pQ->items[pQ->numItems];
    pQ->numItems--;
    fixDown(pQ->items, PQ_ROOT, pQ->numItems);
    return item;
}

/**
 * Helper function for PriorityQueueDelete. Heaps PQ after Deletion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixDown(struct pQItem items[], int i, int numItems) {
    while (2 * i <= numItems) {
        // Setting j to the index of i's left child
        int j = 2 * i;

        // Sets j to the larger of i's children
        if ((j < numItems) && (items[j].priority < items[j + 1].priority)) j++;
        // If the larger child is smaller than the parent, we exit
        if (items[i].priority >= items[j].priority) return;

        // Swaps the item
        struct pQItem temp = items[i];
        items[i] = items[j];
        items[j] = temp;

        // Continue moving down the heap
        i = j;
    }
    return;
}


Item PriorityQueuePeek(PriorityQueue pQ) {
    if (pQ->numItems == 0) {
        fprintf(stderr, "error: cannot peak into empty priority queue");
        exit(EXIT_FAILURE);
    }
    return pQ->items[PQ_ROOT].item;
}

bool PriorityQueueIsEmpty(PriorityQueue pQ) {
    if (pQ->numItems == 0) {
        return true;
    }
    return false;
}

int PriorityQueueSize(PriorityQueue pQ) {
    return pQ->numItems;
}

void PriorityQueuePrint(PriorityQueue pQ) {
    printf("Priority Queue: ");
    for (int i = PQ_ROOT; i <= pQ->numItems; i++) {
        printf("%d", pQ->items[i].item);
        if (i != pQ->numItems) printf(", ");
    }
    printf("\n");
    return;
}