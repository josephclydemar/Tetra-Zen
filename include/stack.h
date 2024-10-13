

#ifndef STACK_H
#define STACK_H

typedef struct SNode {
    void* data;
    struct SNode* next;
} SNode;

typedef struct {
    SNode* top;
    SNode* bottom;
    int count;
} Stack;


SNode* CreateSNode(void* item);
Stack* CreateStack(void);
void Push(Stack* stack, void* item);
void* Pop(Stack* stack);
void* StackPeek(Stack* stack);
void StackTraverse(Stack* stack, char* caption);

#endif

