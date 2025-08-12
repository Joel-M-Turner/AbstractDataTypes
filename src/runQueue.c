// Testing my implementation of Queue ADT

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define INSERT '+'
#define PRINT 'p'
#define DELETE 'd'
#define WHAT '?'
#define SIZE 's'

int main(void) {
    Queue Q = QueueNew();
    char command;
    printf("> ");
    while (scanf(" %c", &command) == 1) {
        if (command == INSERT) {
            int val;
            scanf("%d", &val);
            QueueEnqueue(Q, (Item) {val});
            printf("Inserted %d into the queue\n", val);
        } else if (command == DELETE) {
            if (!QueueIsEmpty(Q)) {
                Item item = QueueDequeue(Q);
                printf("Deleted %d from the queue\n", item);
            } else {
                printf("Queue is empty!\n");
            }            
        } else if (command == SIZE) {
            printf("Queue Size: %d\n", QueueSize(Q));
        } else if (command == PRINT) {
            QueuePrint(Q);
        } else if (command == WHAT) {
            printf(
                "Commands:\n"
                "'+': Add value to queue\n"
                "'d': Delete first value in queue\n"
                "'p': Print Queue\n"
                "'s': Get Size of Queue"
                "'?': Show this message\n"
            );
        }
        printf("> ");
    }
    QueueFree(Q);
    return 0;
}