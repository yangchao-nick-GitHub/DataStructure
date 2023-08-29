#include <stdio.h>
#include "dlist_library.h"


void s_free(void *pointer)
{
    if(pointer) {
        free(pointer);
    }
}