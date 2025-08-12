/**
 * Interface for a Heap ADT. Written by Joel Turner (z5689245),
 * on 02/08/2025
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef HEAP_H
#define HEAP_H

#define INITIAL_CAPACITY 15
#define REALLOCATION_FACTOR 2

typedef struct item {
    // Key which items are sorted by
    int value;
    // Add extra fields according to requirement
} Item;

typedef struct heap {
    Item *items;
    int numItems;
    int capacity;
} *Heap;

/**
 * Creates and allocates memory for a new empty heap
 * Worst-Case Time Complexity: O(1)
 */
Heap HeapNew(void);

/**
 * Inserts an item into the heap
 * Worst-Case Time Complexity: O(log(n))
 */
void HeapInsert(Heap heap, Item item);

/**
 * Deletes the first item in the heap
 * Worst-Case Time Complexity: O(log(n))
 */
Item HeapDelete(Heap heap);

/**
 * Frees all memory associated with the given heap
 * Worst-Case Time Complexity: O(1)
 */
void HeapFree(Heap heap);

/**
 * Checks whether the heap is empty
 * Worst-Case Time Complexity: O(1)
 */
bool HeapIsEmpty(Heap heap);

/**
 * Returns the number of items in the heap
 * Worst-Case Time Complexity: O(1)
 */
int HeapSize(Heap heap);

/**
 * Prints the heap to stdout
 * Worst-Case Time Complexity O(n)
 */
void HeapPrint(Heap heap);

#endif
