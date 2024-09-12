#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include "list.h"


/* CreateList tests */
void Test_ListCountZeroOnCreate(void) {
    List *list = CreateList();

    Test(__func__,
        list->count == 0,
        "Test if the List count is equal to 0 on create");
    free(list);
    list = NULL;
}

void Test_ListHeadNullOnCreate(void) {
    List *list = CreateList();

    Test(__func__,
        list->head == NULL,
        "Test if the List head is equal to NULL on create");
    free(list);
    list = NULL;
}

void Test_ListTailNullOnCreate(void) {
    List *list = CreateList();

    Test(__func__,
        list->tail == NULL,
        "Test if the List tail is equal to NULL on create");
    free(list);
    list = NULL;
}




/* ListAppend tests */
void Test_ListCountOneOnFirstAppend(void) {
    List *list = CreateList();
    
    int *item = (int*)malloc(sizeof(int));
    *item = 9;
    ListAppend(list, (void*)item);

    Test(__func__, 
        list->count == 1,
        "Test if the List count is equal to 1 on the 1st append");
    free(list);
    list = NULL;
}

void Test_ListHeadNotNullOnFirstAppend(void) {
    List *list = CreateList();
    
    int *item = (int*)malloc(sizeof(int));
    *item = 9;
    ListAppend(list, (void*)item);

    Test(__func__, 
        list->head != NULL,
        "Test if the List head is not equal to NULL on the 1st append");
    free(list);
    list = NULL;
}

void Test_ListTailNotNullOnFirstAppend(void) {
    List *list = CreateList();
    
    int *item = (int*)malloc(sizeof(int));
    *item = 9;
    ListAppend(list, (void*)item);

    Test(__func__, 
        list->tail != NULL,
        "Test if the List tail is not equal to NULL on the 1st append");
    free(list);
    list = NULL;
}


void Test_ListCountTwoOnSecondAppend(void) {
    List *list = CreateList();
    
    int *item1 = (int*)malloc(sizeof(int));
    int *item2 = (int*)malloc(sizeof(int));
    *item1 = 4;
    *item2 = 8;
    ListAppend(list, (void*)item1);
    ListAppend(list, (void*)item2);

    Test(__func__, 
        list->count == 0,
        "Test if the List count is equal to 2 on the 2nd append");
    free(list);
    list = NULL;
}




int main() {
    printf("\n%s:\n", __FILE__);
    Test_ListCountZeroOnCreate();
    Test_ListHeadNullOnCreate();
    Test_ListTailNullOnCreate();

    Test_ListCountOneOnFirstAppend();
    Test_ListHeadNotNullOnFirstAppend();
    Test_ListTailNotNullOnFirstAppend();
    Test_ListCountTwoOnSecondAppend();

    return 0;
}