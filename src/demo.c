#include <stdio.h>
#include "dlist_library.h"
#include "dlist.h"

int main()
{
    int rv = 0;
    int a = 10;
    int b = 20;
    dlist_t* new_dlist = dlist_new();
    rv = dlist_append(new_dlist, &a);

    return 0;
}