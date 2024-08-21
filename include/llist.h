#include <stdbool.h>

#ifndef LLIST_H
#define LLIST_H

typedef struct LNode {
    void *data;
    struct LNode *next;
} LNode;

typedef struct {
    LNode *head;
    LNode *tail;
    int count;
} LList;

LNode *CreateLNode(void *item);
LList *CreateLList(void);
bool LListInsert(LList *llist, int index, void *item);
void *LListRemove(LList *llist, int index);
void *LListSearch(LList *llist, int index);
void LListTraverse(LList *llist, int data_type, char *caption);

#endif

