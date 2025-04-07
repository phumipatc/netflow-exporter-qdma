#ifndef BUFFER_LINKED_LIST_H
#define BUFFER_LINKED_LIST_H

#include <stdatomic.h>
#include <stdlib.h>

// circular linked list node
typedef struct DataNode {
    char *data;
    int length;
    _Atomic(struct DataNode*) next;
} DataNode;

// Circular buffer structure
typedef struct {
    _Atomic(DataNode*) producer_ptr;
    _Atomic(DataNode*) consumer_ptr;

} CircularBuffer;

// Function prototypes
void initializeCircularQueue(CircularBuffer* queue, int node_count, int data_size);
void destroyCircularQueue(CircularBuffer* queue);

void moveProducerPtr(CircularBuffer* queue);
void moveConsumerPtr(CircularBuffer* queue);

int getNextNodeToConsume(CircularBuffer* queue);
int getNextNodeToProduce(CircularBuffer* queue);

#endif // BUFFER_LINKED_LIST_H