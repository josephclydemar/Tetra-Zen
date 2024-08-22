#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "llist.h"

LNode *CreateLNode(void *item) {
    LNode *newLNode = (LNode*)malloc(sizeof(LNode));
    newLNode->data = item;
    newLNode->next = NULL;
    return newLNode;
}

LList *CreateLList(void) {
    LList *newLList = (LList*)malloc(sizeof(LList));
    newLList->head = NULL;
    newLList->tail = NULL;
    newLList->count = 0;
    return newLList;
}

bool LListInsert(LList *llist, int index, void *item) {
    if(index < 0) {
        return false;
    }

    LNode *newLNode = CreateLNode(item);
    if(llist->head == NULL) {
        llist->head = newLNode;
        llist->tail = newLNode;
        llist->count++;
        return true;
    }
    if(index == 0) {
        newLNode->next = llist->head;
        llist->head = newLNode;
        llist->count++;
        return true;
    }
    if(index >= llist->count) {
        llist->tail->next = newLNode;
        llist->tail = llist->tail->next;
        llist->count++;
        return true;
    }

    LNode *walker = llist->head;
    for(int i = 0; i < index - 1; i++) {
        walker = walker->next;
    }
    newLNode->next = walker->next;
    walker->next = newLNode;
    llist->count++;
    return true;
}

void *LListRemove(LList *llist, int index) {
    if(index < 0) {
        return NULL;
    }

    if(llist->head == NULL) {
        return NULL;
    }

    LNode *lnodeToRemove;
    void *data;

    if(index == 0) {
        lnodeToRemove = llist->head;
        llist->head = llist->head->next;
        
        data = lnodeToRemove->data;
        lnodeToRemove->next = NULL;
        free(lnodeToRemove);
        
        llist->count--;
        return data;
    }

    if(llist->count == 1) {
        lnodeToRemove = llist->head;
        llist->head = NULL;
        llist->tail = NULL;

        data = lnodeToRemove->data;
        lnodeToRemove->next = NULL;
        free(lnodeToRemove);

        llist->count--;
        return data;
    }

    LNode *walker = llist->head;
    if(index >= llist->count) {
        for(int i = 0; i < llist->count - 2; i++) {
            walker = walker->next;
        }
        lnodeToRemove = walker->next;
        walker->next = NULL;

        data = lnodeToRemove->data;
        lnodeToRemove->next = NULL;
        free(lnodeToRemove);

        llist->count--;
        return data;
    }

    for(int i = 0; i < index - 1; i++) {
        walker = walker->next;
    }
    lnodeToRemove = walker->next;
    walker->next = lnodeToRemove->next;

    data = lnodeToRemove->data;
    lnodeToRemove->next = NULL;
    free(lnodeToRemove);

    llist->count--;
    return data;
}

void *LListSearch(LList *llist, int index) {
    if(index < 0) {
        return NULL;
    }
    if(llist->head == NULL) {
        return NULL;
    }
    if(index >= llist->count) {
        return llist->tail->data;
    }

    LNode *walker = llist->head;
    for(int i = 0; i < index; i++) {
        walker = walker->next;
    }
    return walker->data;
}

void LListTraverse(LList *llist, int data_type, char *caption) {
    printf("\nLLIST [count %3d]: %s\n", llist->count, caption);
    if(llist->head == NULL) {
        printf("EMPTY LIST\n");
        return;
    }

    LNode *walker = llist->head;
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


