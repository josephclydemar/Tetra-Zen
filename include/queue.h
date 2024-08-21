
#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode {
    void *data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
    int count;
} Queue;

QNode *CreateQNode(void *item);
Queue *CreateQueue(void);
void Enqueue(Queue *queue, void *item);
void *Dequeue(Queue *queue);
void *QueuePeek(Queue *queue);
void QueueTraverse(Queue *queue, char *caption);

#endif

