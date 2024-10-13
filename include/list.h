

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>


typedef struct LNode {
    int id;
    void* data;
    struct LNode* next;
} LNode;

typedef struct {
    LNode* head;
    LNode* tail;
    int count;
} List;

LNode* CreateLNode(int id, void* item);
List* CreateList(void);
void DestroyList(List* list);
bool ListAppend(List* list, void* item);
void* ListRemove(List* list, int id);
void* ListSearch(List* list, int id);
void ListTraverse(List* list, int data_type, char* caption);

#endif

