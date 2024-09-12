#include <stdio.h>
#include "testing.h"
#include "stack.h"

void Test_CreateStack(void) {
    Stack *stackToTest = CreateStack();
    
    Test(__func__, 
        stackToTest->top == NULL,
        "Test if the Stack was created properly");
}

int main(void) {
    printf("\n%s:\n", __FILE__);
    Test_CreateStack();
    return 0;
}