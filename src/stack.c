#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

SNode *CreateSNode(void *item) {
    SNode *newSNode = (SNode*)malloc(sizeof(SNode));
    newSNode->data = item;
    newSNode->next = NULL;
    return newSNode;
}

Stack *CreateStack(void) {
    Stack *newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    newStack->bottom = NULL;
    newStack->count = 0;
    return newStack;
}

void Push(Stack *stack, void *item) {
    SNode *newSNode = CreateSNode(item);
    newSNode->next = stack->top;
    stack->top = newSNode;
    if(stack->count == 0) {
        stack->bottom = newSNode;
    }
    stack->count++;
}

void *Pop(Stack *stack) {
    if(stack->top == NULL) {
        return NULL;
    }
    SNode *snodeToPop = stack->top;
    void *item = stack->top->data;
    stack->top = stack->top->next;
    if(stack->count == 1) {
        stack->bottom = NULL;
    }
    free(snodeToPop);
    stack->count--;
    snodeToPop = NULL;
    return item;
}

void *StackPeek(Stack *stack) {
    if(stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

void StackTraverse(Stack *stack, char *caption) {
    SNode *walker = stack->top;
    printf("\n%s ->  [", caption);
    while(walker != NULL) {
        printf("%2p", walker->data);
        walker = walker->next;
    }
    printf("  ]\n");
}


