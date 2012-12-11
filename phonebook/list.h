#ifndef LIST_H
#define LIST_H

#include <string.h>
#include <stdlib.h>
#include "database.h"

/**
Add an element to the list
*/
void list_put(ContactList **list, Contact *cntct);

/**
Gets the next element from the list
*/
Contact * list_getNext(ContactList *list);

/**
Frees the list
*/
void list_free(ContactList **list);

#endif