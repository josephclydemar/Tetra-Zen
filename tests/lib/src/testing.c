#include <stdio.h>
#include "testing.h"

bool Test(const char *_func_name, bool _condition, const char *_description) {
    if(_condition == false) {
        printf("    \033[0m[\033[31mFAILED\033[0m] \033[33m%s\033[0m : %s\n", _func_name, _description);
        return false;
    }
    printf("    \033[0m[\033[32mPASSED\033[0m] \033[33m%s\033[0m : %s\n", _func_name, _description);
    return true;
}

