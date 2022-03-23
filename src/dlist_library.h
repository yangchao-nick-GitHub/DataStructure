#ifndef __DLIST_LIBRARY_H__
#define __DLIST_LIBRARY_H__

#include <stdlib.h>

typedef int (dlist_compare_func) (void *item1, void *item2);
typedef struct dnode_s {
    void *data;
    struct dnode_s *prev;
    struct dnode_s *next;
}dnode_t;

typedef struct dlist_s {
    int size;
    dlist_compare_func *fn;;
    dnode_t *head;
    dnode_t *tail;
}dlist_t;



void s_free(void *pointer);

#endif
