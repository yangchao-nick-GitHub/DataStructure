#include <stdio.h>
#include "dlist.h"
#include "dlist_library.h"

dlist_t* dlist_new(void)
{
    dlist_t *dlist = NULL;
    dlist = (dlist_t*)malloc(sizeof(dlist_t));
    if (dlist == NULL) {
        return NULL;
    }

    dlist->head = (dnode_t*)malloc(sizeof(dnode_t));
    if (dlist->head == NULL) {
        s_free(dlist);
        return NULL;
    }

    dlist->size = 0;
    dlist->tail = dlist->head;
    dlist->tail->next = dlist->head;
    dlist->head->prev = dlist->tail;

    return dlist;
}

int dlist_append(dlist_t *dlist_p, void *item)
{
    if (dlist_p == NULL || dlist_p->head == NULL) {
        return -1;
    }

    dnode_t *dlist_node = (dnode_t*)malloc(sizeof(dnode_t));
    if (dlist_node == NULL) {
        return -1;
    }

    dlist_node->data = item;
    dlist_node->prev = dlist_p->tail;
    dlist_p->tail->next = dlist_node;

    dlist_p->tail = dlist_node;
    dlist_p->tail->next = dlist_p->head;
    dlist_p->head->prev = dlist_p->tail;
    dlist_p->size++;

    return 0;
}

int dlist_size(dlist_t *dlist_p)
{
    if (dlist_p == NULL || dlist_p->head == NULL) {
        return 0;
    }

    return dlist_p->size;
}

void dlist_destroy(dlist_t *dlist_p)
{
    int i = 0;
    dnode_t *pos = NULL;
    dnode_t *cur = NULL;
    if (dlist_p == NULL) {
        return ;
    }

    if (dlist_p->head == NULL) {
        free(dlist_p);
        return ;
    }

    pos = dlist_p->tail;
    while(pos != dlist_p->head) {
        cur = pos->prev;
        free(pos);
        pos = cur;
    }

    free(dlist_p->head);
    free(dlist_p);    
}


void* dlist_pos_visit(dlist_t *dlist_p, int pos)
{
    dnode_t *tmp = NULL;
    int size = 0;
    size = dlist_size(dlist_p);
    if (dlist_p == NULL || dlist_p->head == NULL) {
        return NULL;
    }
    tmp = dlist_p->head;

    if (pos < 1 || pos > size) {
        return NULL;
    }

    for (size = 1; size <= pos; size++) {
        tmp = tmp->next;
    }
    
    return tmp->data;
}

int dlist_push(dlist_t *dlist_p, void *item)
{
    if (dlist_p == NULL || dlist_p->head == NULL) {
        return -1;
    }

    dnode_t *dlist_node = (dnode_t*)malloc(sizeof(dnode_t));
    if (dlist_node == NULL) {
        return -1;
    }

    dlist_node->data = item;
    dlist_node->next = dlist_p->head->next;
    dlist_p->head->next = dlist_node;
    dlist_node->next->prev = dlist_node;
    dlist_node->prev = dlist_p->head;


    dlist_p->size++;

    return 0;
}

int dlist_compare_fn(dlist_t *dlist_p, dlist_compare_func fn)
{
    if (dlist_p == NULL || dlist_p->head == NULL) {
        return -1;
    }

    dlist_p->fn = fn;
}

int dlist_exist(dlist_t *dlist_p, void *item)
{
    int exist = 0;
    int i;
    int size = 0;
    dnode_t *tmp = NULL;
    if (dlist_p == NULL || dlist_p->head == NULL) {
        return -1;
    }
    size = dlist_size(dlist_p);
    for (i = 1; i <= size; i++) {
        tmp = dlist_pos_visit(dlist_p, i);
        exist = dlist_p->fn(tmp->data, item);
        if (exist == 1) {
            return 1;
        }
    }
     
    return 0;   
}
    



