
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QNode *CreateQNode(void *item) {
    QNode *new_node = (QNode*)malloc(sizeof(QNode));
    new_node->data = item;
    new_node->next = NULL;
    return new_node;
}

Queue *CreateQueue(void) {
    Queue *new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->count = 0;
    return new_queue;
}

void Enqueue(Queue *queue, void *item) {
    QNode *new_node = CreateQNode(item);
    if(queue->count == 0) {
        queue->rear = new_node;
        queue->front = queue->rear;
        queue->count++;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
    queue->count++;
    return;
}

void *Dequeue(Queue *queue) {
    if(queue->count == 0) {
        return NULL;
    }
    QNode *node_to_remove = queue->front;
    void *item = node_to_remove->data;
    queue->front = node_to_remove->next;
    free(node_to_remove);
    queue->count--;
    return item;
}

void *QueuePeek(Queue *queue) {
    if(queue->count == 0) {
        return NULL;
    }
    return queue->front->data;
}

void QueueTraverse(Queue *queue, char *caption) {
    QNode *walker = queue->front;
    printf("\n%s ->  [", caption);
    while(walker != NULL) {
        printf("%2p", walker->data);
        walker = walker->next;
    }
    printf(" ]\n");
}


