// Testing my implementation of Priority Queue ADT

#include <stdio.h>
#include <stdlib.h>

#include "PriorityQueue.h"

#define INSERT '+'
#define PRINT 'p'
#define DELETE 'd'
#define WHAT '?'
#define SIZE 's'

int main(void) {
    PriorityQueue pQ = PriorityQueueNew();
    char command;
    printf("> ");
    while (scanf(" %c", &command) == 1) {
        if (command == INSERT) {
            int val;
            scanf("%d", &val);
            PriorityQueueInsert(pQ, (Item) {val}, val);
            printf("Inserted %d into the heap\n", val);
        } else if (command == DELETE) {
            if (!PriorityQueueIsEmpty(pQ)) {
                Item item = PriorityQueueDelete(pQ);
                printf("Deleted %d from the Priority Queue\n", item);
            } else {
                printf("Priority Queue is empty!\n");
            }            
        } else if (command == SIZE) {
            printf("Priority Queue Size: %d\n", PriorityQueueSize(pQ));
        } else if (command == PRINT) {
            PriorityQueuePrint(pQ);
        } else if (command == WHAT) {
            printf(
                "Commands:\n"
                "'+': Add value to heap\n"
                "'d': Delete first value in heap\n"
                "'p': Print Priority Queue\n"
                "'s': Get Size of heap"
                "'?': Show this message\n"
            );
        }
        printf("> ");
    }
    PriorityQueueFree(pQ);
    return 0;
}