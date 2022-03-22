#ifndef __DLIST_H__
#define __DLIST_H__
#include "dlist_library.h"


// Create a new dlist
dlist_t* dlist_new(void);

// Destroy a dlist
void dlist_destroy(dlist_t *dlist_p);

// Return the item at the head of dlist. If the dlist is empty, returns NULL.
void* dlist_first(dlist_t *dlist_p);

// Return the next item. If the dlist is empty, returns NULL. 
void* dlist_next(dlist_t *dlist_p);

// Return the item at the tail of dlist. If the dlist is empty, returns NULL.
void* dlist_last(dlist_t *dlist_p);

// Append an item to the end of the dlist, return 0 if OK or -1 if failed.
int dlist_append(dlist_t *dlist_p, void *item);

// Push an item to the end of the dlist, return 0 if OK or i1 if failed.
int dlist_push(dlist_t *dlist_p, void *item);

// Check if an item already is present. Uses compare method to check if 
// items are equal. if the compare method is NULL, the check will only 
// compare pointer. Return ture if item is present else false.
int dlist_exist(dlist_t *dlist_p, void *item);

// Remove the specified item from the dlist if present.
void dlist_remove(dlist_t *dlist_p, void *item);

// Return the number of item in the dlist
int dlist_size(dlist_t *dlist_p);












#endif