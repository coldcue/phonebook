#include "list.h"

void list_put(ContactList **list, Contact *cntct){
	ContactList *e, *lp;

	e = (ContactList*) malloc(sizeof(ContactList));
	e->cntct = cntct;
	e->next = NULL;

	if(*list==NULL) {
		*list = e;
		return;
	}

	lp=*list; 
	while(lp->next!=NULL) lp=lp->next; 
	lp->next=e;

	return;
}

Contact * list_getNext(ContactList *listp)
{
	if(listp->next==NULL) return NULL;
	listp = listp->next;
	return listp->cntct;
}

void list_free(ContactList **list)
{
	ContactList *first = *list;
	while(first!=NULL)
	{
		ContactList *tmp = first->next;
		free(first);
		first = tmp;
	}
}
