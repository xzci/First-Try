#ifndef LIST_H

#define LIST_H

#include <stdlib.h>
typedef struct ListElmt_
{
	void *data; // can use point to get the real data
	struct ListElmt_ * next;
} ListElmt;

typedef struct List_
{
	int size;
	int(*match)(const void *key1, const void *key2);
	void(*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

void list_init(List *list, void(*destroy)(void *data));
void list_destroy(List *list);

// should use bool but C do not give bool before C99
int list_ins_next(List *list, ListElmt *element, const void * data);
/* when you want to remove a element, you should give the value to the programer
/ because they want to use this data, you can not just delete the element and do nothing
/ also the element can be return as return value, but in this way, you can not judge
/ if it has been remove already */
int list_rem_next(List *list, ListElmt *element, void **data);

// in other language you should use inline function instead of using macro
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif // !LIST_H

