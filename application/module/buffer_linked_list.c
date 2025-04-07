#include "buffer_linked_list.h"

/**
 * initializeCircularQueue
 * - Initializes the circular buffer with NODE_COUNT number of nodes
 * - Need to be called before spawning any threads
*/
void initializeCircularQueue(CircularBuffer* queue, int node_count, int data_size) {
    DataNode* head = NULL;
    DataNode* prev = NULL;

    for(int i=0;i<node_count;i++) {
        DataNode* node = (DataNode*)malloc(sizeof(DataNode));
		node->data = (char*)malloc(data_size);
        memset(node->data, 0, data_size);
        node->length = 0;
        node->next = NULL;

        if (!head) {
            head = node;
        } else {
            prev->next = node;
        }
        prev = node;
    }
    prev->next = head;

    queue->producer_ptr = head->next;
    queue->consumer_ptr = head;

}

/**
 * destroyCircularQueue
 * - Frees the memory allocated for the circular buffer
 * - Need to be called after all threads have exited
*/
void destroyCircularQueue(CircularBuffer* queue) {
    DataNode* head = queue->producer_ptr;
    DataNode* current = head;
    DataNode* next = head->next;

    while(next != head) {
        free(current);
        current = next;
        next = next->next;
    }

    free(current);
}

/**
 * moveProducerPtr
 * - Moves the producer pointer to the next node in the circular buffer
 * - Requires atomic operations to ensure thread safety
*/
void moveProducerPtr(CircularBuffer* queue) {
    atomic_store(&queue->producer_ptr, atomic_load(&queue->producer_ptr)->next);
}

/**
 * moveConsumerPtr
 * - Moves the consumer pointer to the next node in the circular buffer
 * - Requires atomic operations to ensure thread safety
*/
void moveConsumerPtr(CircularBuffer* queue) {
    atomic_store(&queue->consumer_ptr, atomic_load(&queue->consumer_ptr)->next);
}

/**
 * getNextNodeToConsume
 * - If the consumer has not caught up with the producer, moves the consumer pointer to the next node in the circular buffer
 * Returns:
 * - 0 if the consumer has caught up with the producer
 * - 1 if the consumer has not caught up with the producer, and the consumer pointer has been moved
*/
int getNextNodeToConsume(CircularBuffer* queue) {
    // check if consumer has caught up with producer
    if(atomic_load(&queue->consumer_ptr)->next == atomic_load(&queue->producer_ptr)) {
        return 0;
    }

    moveConsumerPtr(queue);

    return 1;
}

/**
 * getNextNodeToProduce
 * - If the producer has not caught up with the consumer, moves the producer pointer to the next node in the circular buffer
 * Returns:
 * - 0 if the next node is the same as the consumer node
 * - 1 if the next node is different from the consumer node, and the producer pointer has been moved
*/
int getNextNodeToProduce(CircularBuffer* queue) {
    // check if producer has caught up with consumer
    if(atomic_load(&queue->producer_ptr)->next == atomic_load(&queue->consumer_ptr)) {
        return 0;
    }

    moveProducerPtr(queue);

    return 1;
}