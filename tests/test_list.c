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




int main() {
    printf("\n%s:\n", __FILE__);
    Test_ListCountZeroOnCreate();
    Test_ListHeadNullOnCreate();
    Test_ListTailNullOnCreate();

    return 0;
}