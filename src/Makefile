CC = clang
CFLAGS = -Wall -Wvla -Werror -gdwarf-4

########################################################################

.PHONY: asan msan nosan

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

.PHONY: all
all: runHeap runPriorityQueue runQueue

runHeap: runHeap.c Heap.c
runPriorityQueue: runPriorityQueue.c PriorityQueue.c
runQueue: runQueue.c Queue.c

.PHONY: clean
clean:
	rm -f *.o runHeap runPriorityQueue runQueue

