#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "list.h"

LNode *CreateLNode(int id, void *item) {
    LNode *newLNode = (LNode*)malloc(sizeof(LNode));
    newLNode->id = id;
    newLNode->data = item;
    newLNode->next = NULL;
    return newLNode;
}

List *CreateList(void) {
    List *newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->count = 0;
    return newList;
}

bool ListAppend(List *list, void *item) {
    if(list->count == 0 && list->head == NULL && list->tail == NULL) {
        LNode *newLNode = CreateLNode(0, item);
        list->head = newLNode;
        list->tail = newLNode;
        list->count++;
    }
    
    assert(list->head != NULL);
    assert(list->tail != NULL);
    assert(list->count > 0);

    LNode *newLNode = CreateLNode(list->count, item);
    list->tail->next = newLNode;
    list->tail = list->tail->next;
    list->count++;
    return true;
}

void *ListRemove(List *list, int id) {
    assert(id > -1);
    assert(id < list->count);

    if(list->count == 0 && list->head == NULL && list->tail == NULL) {
        return NULL;
    }
    
    void *data;
    LNode *walker = list->head;
    LNode *lnodeToRemove;

    if(list->count == 1) {
        data = walker->data;
        free(walker);
        list->head = NULL;
        list->tail = NULL;
        list->count--;
        return data;
    }

    if(id == list->count - 1) {
        while(walker->next != NULL) {
            walker = walker->next;
        }
        lnodeToRemove = walker->next;
        data = lnodeToRemove->data;

        list->tail = walker;
        list->tail->next = NULL;
        
        free(lnodeToRemove);
        list->count--;
        return data;
    }

    while(walker->next != NULL) {
        if(walker->next->id == id) {
            lnodeToRemove = walker->next;
            data = lnodeToRemove->data;
            walker->next = lnodeToRemove->next;
            free(lnodeToRemove);
            list->count--;
            return data;
        }
        walker = walker->next;
    }
    return NULL;
}

void *ListSearch(List *list, int id) {
    if(id < 0) {
        return NULL;
    }
    if(list->head == NULL) {
        return NULL;
    }
    if(id >= list->count) {
        return list->tail->data;
    }

    LNode *walker = list->head;
    for(int i = 0; i < id; i++) {
        walker = walker->next;
    }
    return walker->data;
}

void ListTraverse(List *list, int data_type, char *caption) {
    printf("\nLIST [count %3d]: %s\n", list->count, caption);
    if(list->head == NULL) {
        printf("EMPTY LIST\n");
        return;
    }

    LNode *walker = list->head;
    while(walker != NULL) {
        switch(data_type) {
            case 0:
                printf("[%3d] ", *(int*)(walker->data));
                break;
            case 1:
                printf("[%3.4lf] ", *(double*)(walker->data));
                break;
            case 2:
                printf("[%c] ", *(char*)(walker->data));
                break;
            case 3:
                printf("[%s] ", (char*)(walker->data));
                break;
            default:
                printf("[%p] ", walker->data);
        }
        walker = walker->next;
    }
    printf("\n");
}


