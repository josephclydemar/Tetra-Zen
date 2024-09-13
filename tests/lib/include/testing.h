
#ifndef TESTING_H
#define TESTING_H

#include <stddef.h>
#include <stdbool.h>


#define BLACK_FORE      "\033[30m"
#define BLACK_BACK      "\033[40m"


#define RED_FORE        "\033[31m"
#define RED_BACK        "\033[41m"

#define LIGHTRED_FORE   "\033[91m"
#define LIGHTRED_BACK   "\033[101m"


#define GREEN_FORE      "\033[32m"
#define GREEN_BACK      "\033[42m"

#define LIGHTGREEN_FORE "\033[92m"
#define LIGHTGREEN_BACK "\033[102m"


#define YELLOW_FORE	    "\033[33m"
#define YELLOW_BACK	    "\033[43m"


#define BLUE_FORE       "\033[34m"
#define BLUE_BACK       "\033[44m"


#define MAGENTA_FORE	"\033[35m"
#define MAGENTA_BACK	"\033[45m"


#define CYAN_FORE       "\033[36m"
#define CYAN_BACK       "\033[46m"


#define DEFAULT_FORE	"\033[0m"


bool Test(const char *_func_name, const bool _condition, const char *_description);


#endif
