// Testing my implementation of Heap ADT

#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

#define INSERT '+'
#define PRINT 'p'
#define DELETE 'd'
#define WHAT '?'
#define SIZE 's'

int main(void) {
    Heap Heap = HeapNew();
    char command;
    printf("> ");
    while (scanf(" %c", &command) == 1) {
        if (command == INSERT) {
            int val;
            scanf("%d", &val);
            HeapInsert(Heap, (Item) {val});
            printf("Inserted %d into the heap\n", val);
        } else if (command == DELETE) {
            if (!HeapIsEmpty(Heap)) {
                Item item = HeapDelete(Heap);
                printf("Deleted %d from the Heap\n", item.value);
            } else {
                printf("Heap is empty!\n");
            }            
        } else if (command == SIZE) {
            printf("Heap Size: %d\n", HeapSize(Heap));
        } else if (command == PRINT) {
            HeapPrint(Heap);
        } else if (command == WHAT) {
            printf(
                "Commands:\n"
                "'+': Add value to heap\n"
                "'d': Delete first value in heap\n"
                "'p': Print Heap\n"
                "'s': Get Size of heap"
                "'?': Show this message\n"
            );
        }
        printf("> ");
    }
    HeapFree(Heap);
    return 0;
}