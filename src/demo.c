#include <stdio.h>
#include "dlist_library.h"
#include "dlist.h"

int compare_item(void *item1, void *item2)
{
    int *data1 = NULL;
    int *data2 = NULL;
    
    data1 = (int*)item1;
    data2 = (int*)item2;

    fprintf(stdout,"data1 %d data2 %d\n",*data1, *data2);
    
    if (data1 == data2) {
        return 1;
    }

    return 0;
}

int main()
{
    int rv = 0;
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int f = 50;
    int i = 0;
    int size = 0;
    int exist = 0;
    int *data = NULL;
    dlist_t* new_dlist = dlist_new();
    dlist_compare_fn(new_dlist, (dlist_compare_func*)compare_item);
    dlist_append(new_dlist, &a);
    dlist_append(new_dlist, &b);
    dlist_append(new_dlist, &c);
    dlist_push(new_dlist, &d);
    dlist_push(new_dlist, &f);
    size = dlist_size(new_dlist);
    fprintf(stdout,"dlist size %d\n",size);

    for (i = 1; i <= size; i++)
    {
        data = dlist_pos_visit(new_dlist, i);
        fprintf(stdout,"data %d\n",*data);
    }

    //fprintf(stdout,"exist %d\n",dlist_exist(new_dlist, &c));

    

    dlist_destroy(new_dlist);
    return 0;
}