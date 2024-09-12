
#ifndef TESTING_H
#define TESTING_H

#include <stddef.h>
#include <stdbool.h>


// #define BLACK_FORE      "\0[30m"
// #define BLACK_BACK      "\0[40m"

// #define RED_FORE        "\0[31m"
// #define RED_BACK        "\0[41m"

// #define GREEN_FORE      "\0[32m"
// #define GREEN_BACK      "\0[42m"

// #define YELLOW_FORE	    "\0[33m"
// #define YELLOW_BACK	    "\0[43m"

// #define BLUE_FORE       "\0[34m"
// #define BLUE_BACK       "\0[44m"

// #define MAGENTA_FORE	"\0[35m"
// #define MAGENTA_BACK	"\0[45m"

// #define CYAN_FORE       "\0[36m"
// #define CYAN_BACK       "\0[46m"

// #define DEFAULT_FORE	"\0[0m"


bool Test(const char *_func_name, const bool _condition, const char *_description);


#endif