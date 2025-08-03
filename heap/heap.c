/**
 * Implementation for a Priority Queue ADT. Written by Joel Turner (z5689245),
 * on 02/08/2025.
 * Implementation Details:
 * - Uses Max Heap Implementation
 * - Interprets Higher Numbers as Higher Priority
*/

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define HEAP_ROOT 1

//------------------------------Helper Functions------------------------------//

/**
 * Helper function for HeapInsert
 * Repeatedly swaps the ith item with its parent
 * until it is less than its parent, or it is the root
 * Worst-Case Time Complexity: O(log(n) since the number 
 * of levels of the heap binary tree is always floor(log(n))
 */
void fixUp(Item items[], int i);

/**
 * Helper function for HeapDelete
 * Repeatedly swaps the root node with its 
 * child until it is greater than its children.
 * Worst-Case Time Complexity: O(log(n) since the number 
 * of levels of the heap binary tree is always floor(log(n))
 */
void fixDown(Item items[], int i, int numItems);

//-------------------------------Implementation-------------------------------//

/**
 * Creates and allocates memory for a new empty heap
 * Worst-Case Time Complexity: O(1)
 */
struct heap *HeapNew(void) {
    Heap heap = malloc(sizeof(*heap));

    // Checking storage isn't empty
    if (heap == NULL) {
        fprintf(stderr, "error: unable to allocate heap");
        exit(EXIT_FAILURE);
    }

    heap->numItems = 0;
    heap->capacity = INITIAL_CAPACITY;
    heap->items = malloc((heap->capacity + 1) * sizeof(Item));
    
    // Checking storage isn't empty
    if (heap->items == NULL) {
        fprintf(stderr, "error: unable to allocate heap");
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
        heap->items = realloc(
            heap->items,
            (heap->capacity * REALLOCATION_FACTOR + 1) * (sizeof(Item))
        );        
        heap->capacity = heap->capacity * REALLOCATION_FACTOR;
    }
    // Error if no memory left
    if (heap->items == NULL) {
        fprintf(stderr, "error: unable to reallocate heap");
        exit(EXIT_FAILURE);
    }

    heap->numItems++;
    heap->items[heap->numItems] = item;
    fixUp(heap->items, heap->numItems);

    return;    
}

/**
 * Helper function for HeapInsert
 * Keeps swapping the ith item with its parent
 * until it is less than its parent, or it is the root
 * Worst-Case Time Complexity: O(log(n) since the number 
 * of levels of the heap binary tree is always floor(log(n))
 */
void fixUp(Item items[], int i) {
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

    Item item = heap->items[HEAP_ROOT];
    heap->items[HEAP_ROOT] = heap->items[heap->numItems];
    heap->numItems--;
    fixDown(heap->items, HEAP_ROOT, heap->numItems);
    return item;
}

/**
 * Helper function for HeapDelete
 * Repeatedly swaps the node with index i with 
 * its child until it is greater than its children.
 * Worst-Case Time Complexity: O(log(n) since the number 
 * of levels of the heap binary tree is always floor(log(n))
 */
void fixDown(Item items[], int i, int numItems) {
    while (2 * i <= numItems) {
        // Setting j to the index of i's left child
        int j = 2 * i;

        // Sets j to the larger of i's children
        if ((j < numItems) && (items[j].value < items[j + 1].value)) {
            j++;
        }

        // If the larger child is smaller than the parent, we exit
        if (items[i].value >= items[j].value) {
            return;
        }

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