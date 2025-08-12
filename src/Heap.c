/**
 * Implementation for a Heap ADT. Written by Joel Turner (z5689245),
 * on 02/08/2025.
 * Implementation Details:
 * - Uses Max Heap Implementation
*/

#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

#define HEAP_ROOT 1

//------------------------------Helper Functions------------------------------//

/**
 * Helper function for PriorityQueueInsert. Heaps the heap after Insertion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixUp(Item items[], int i);

/**
 * Helper function for PriorityQueueInsert. Heaps the heap after Deletion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixDown(Item items[], int i, int numItems);

/**
 * Helper function for HeapInsert. Increases the size of the Heap, by a factor 
 * defined in Heap.h (REALLOCATION_FACTOR).
 * Worst-Case Time Complexity: O(n)
 */
static void resizeHeap(Heap heap) ;

//-------------------------------Implementation-------------------------------//

/**
 * Creates and allocates memory for a new empty heap
 * Worst-Case Time Complexity: O(1)
 */
struct heap *HeapNew(void) {
    Heap heap = malloc(sizeof(*heap));

    // Checking storage isn't empty
    if (heap == NULL) {
        fprintf(stderr, "error: unable to allocate heap\n");
        exit(EXIT_FAILURE);
    }

    heap->numItems = 0;
    heap->capacity = INITIAL_CAPACITY;
    heap->items = malloc((heap->capacity + 1) * sizeof(Item));
    
    // Checking storage isn't empty
    if (heap->items == NULL) {
        fprintf(stderr, "error: unable to allocate heap\n");
        exit(EXIT_FAILURE);
    }

    return heap;
}

/**
 * Inserts an item into the heap
 * Worst-Case Time Complexity: O(log(n)) || O(n)
 *      - Resizing the heap is O(n)
 *      - Adding an item to the last slot is O(1)
 *      - fixUp is O(log(n))
 */
void HeapInsert(Heap heap, Item item) {
    // Resizes if the heap is full
    if (heap->numItems == heap->capacity) {
        resizeHeap(heap);
    }

    heap->numItems++;
    heap->items[heap->numItems] = item;
    fixUp(heap->items, heap->numItems);

    return;    
}

/**
 * Helper function for HeapInsert. Increases the size of the Heap, by a factor 
 * defined in Heap.h (REALLOCATION_FACTOR).
 * Worst-Case Time Complexity: O(n)
 */
static void resizeHeap(Heap heap) {
    heap->capacity *= REALLOCATION_FACTOR;
    heap->items = realloc(heap->items, (heap->capacity + 1) * (sizeof(Item))); 
    if (heap->items == NULL) {
        fprintf(stderr, "error: unable to reallocate heap\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Helper function for PriorityQueueInsert. Heaps the heap after Insertion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixUp(Item items[], int i) {
    while ((i > HEAP_ROOT) && (items[i].value > items[i / 2].value)) {
        // Swap items[i] and items[i/2]
        Item temp = items[i/2];
        items[i/2] = items[i];
        items[i] = temp;
        i = i / 2;
    }
    return;
}

/**
 * Deletes the first item in the heap. Assumes the Heap
 * is not empty
 * Worst-Case Time Complexity: O(log(n))
 *      - Swapping the root and the last item is O(1)
 *      - fixDown() is O(log(n))
 */
Item HeapDelete(Heap heap) {
    if (heap->numItems == 0) {
        fprintf(stderr, "error: cannot delete from empty heap");
        exit(EXIT_FAILURE);
    }
    Item item = heap->items[HEAP_ROOT];
    heap->items[HEAP_ROOT] = heap->items[heap->numItems];
    heap->numItems--;
    fixDown(heap->items, HEAP_ROOT, heap->numItems);
    return item;
}

/**
 * Helper function for PriorityQueueInsert. Heaps the heap after Deletion.
 * Worst-Case Time Complexity: O(log(n))
 */
static void fixDown(Item items[], int i, int numItems) {
    while (2 * i <= numItems) {
        // Setting j to the index of i's left child
        int j = 2 * i;

        // Sets j to the larger of i's children
        if ((j < numItems) && (items[j].value < items[j + 1].value)) j++;
        // If the larger child is smaller than the parent, we exit
        if (items[i].value >= items[j].value) return;

        // Swaps the item
        Item temp = items[i];
        items[i] = items[j];
        items[j] = temp;

        // Continue moving down the heap
        i = j;
    }
    return;
}

/**
 * Frees all memory associated with the given heap
 * Worst-Case Time Complexity: O(1)
 */
void HeapFree(Heap heap) {
    free(heap->items);
    free(heap);    
    return;
}

/**
 * Checks whether the heap is empty
 * Worst-Case Time Complexity: O(1)
 */
bool HeapIsEmpty(Heap heap) {
    if (heap->numItems == 0) {
        return true;
    }
    return false;
}

/**
 * Returns the number of items in the heap
 * Worst-Case Time Complexity: O(1)
 */
int HeapSize(Heap heap) {
    return heap->numItems;
}

/**
 * Prints the heap to stdout
 * Worst-Case Time Complexity O(n)
 */
void HeapPrint(Heap heap) {
    printf("Heap:");
    for (int i = HEAP_ROOT; i <= heap->numItems; i++) {
        printf(" %d |", heap->items[i].value);
    }
    printf("\n");
    return;
}