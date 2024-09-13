#include <stdio.h>
#include "testing.h"

bool Test(const char *_func_name, bool _condition, const char *_description) {
    if(_condition) {
        printf("    %s%s PASSED %s %s%s%s : %s\n",
            LIGHTGREEN_BACK, 
            BLACK_FORE, 
            DEFAULT_FORE, 
            YELLOW_FORE, 
            _func_name, 
            DEFAULT_FORE, 
            _description);
        return true;
    }
    printf("    %s%s FAILED %s %s%s%s : %s\n", 
        RED_BACK, 
        BLACK_FORE, 
        DEFAULT_FORE, 
        YELLOW_FORE, 
        _func_name, 
        DEFAULT_FORE, 
        _description);
    return false;
}
