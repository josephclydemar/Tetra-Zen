#include <stdio.h>
#include "testing.h"
#include "queue.h"

void Test_QueueCountZeroOnCreate(void) {
    Queue *queueToTest = CreateQueue();
    
    Test(__func__, 
        queueToTest->count == 0,
        "Test if the Queue count is equal to 0 on create");
}

void Test_QueueFrontNullOnCreate(void) {
    Queue *queueToTest = CreateQueue();
    
    Test(__func__, 
        queueToTest->front == NULL,
        "Test if the Queue front is equal to NULL on create");
}

void Test_QueueRearNullOnCreate(void) {
    Queue *queueToTest = CreateQueue();
    
    Test(__func__, 
        queueToTest->rear == NULL,
        "Test if the Queue rear is equal to NULL on create");
}


int main(void) {
    printf("\n%s:\n", __FILE__);
    Test_QueueCountZeroOnCreate();
    Test_QueueFrontNullOnCreate();
    Test_QueueRearNullOnCreate();
    return 0;
}