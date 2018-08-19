#include <stdio.h>
#include <stdlib.h>

typedef int (*ItemFunction)(struct Element *e);

int clear(struct List *list);
void init(struct List *list);
void print(struct List *list);
int printItem(struct Element* element);
int removeElements(struct List* list, int val);
void insert(struct List *list, int val, char* dat);
int forall(struct List *list, ItemFunction exec);

struct Element
{
	char datum[11];
	unsigned tagesproduktion;	//Daten des Listenelements
	struct Element* next; //Zeiger auf das nächste Listenelement
};

struct List
{
	struct Element* first;
	struct Element* last;
}base;

void main()
{
	struct List list;
	init(&list);
	insert(&list, 1, "18.11.11");
	insert(&list, 1, "19.11.11");
	insert(&list, 5, "20.11.11");
	insert(&list, 5, "21.11.11");
	insert(&list, 0, "22.11.11");
	print(&list);
	int deleted = removeElements(&list, 1);
	printf("Removed: %d\n", deleted);
	printf("-------------\n");
	print(&list);
	deleted = removeElements(&list, 0);
	printf("Removed: %d\n", deleted);
	printf("-------------\n");
	print(&list);
	deleted = removeElements(&list, 5);
	printf("Removed: %d\n", deleted);
	printf("-------------\n");
	print(&list);
	printf("-------------\n");
	clear(&list);

	_getch();
	return 0;
	system("pause");
}

void init(struct List *base)
{
	base->first = NULL;
	base->last = NULL;
}

void insert(struct List *list, int val, char* dat)
{
	struct Element *e = (struct Element*) malloc(sizeof(struct Element));
	strcpy(e->datum, dat); //wegen Speicherüberlauf
	e->tagesproduktion = val;
	e->next = list->first;
	list->first = e;
}

void print(struct List *list)
{
	forall(list, printItem);
}

int removeElements(struct List* list, int val)
{
	int delete_count = 0;
	for (struct Element *e = list->first; e->tagesproduktion == val; e = list->first)
	{
		if (list->first->next != NULL)
		{
			list->first = list->first->next;
			delete_count++;
			free(e);
		}
		else
		{
			list->first = NULL;
			delete_count++;
			free(e);
			break;
		}
	}

	if (list->first != NULL)
	{
		struct Element *e;
		for (e = list->first; e->next != NULL; e = e->next)
		{
			if (e->next->tagesproduktion == val)
			{
				struct Element *buffer = e->next;
				e->next = e->next->next;
				delete_count++;
				free(buffer);

				if (e->next->tagesproduktion == val)
				{
					free(e->next);
					e->next = NULL;
					delete_count++;
					break;
				}
			}
		}
	}
	return delete_count;
}

int clear(struct List *list)
{
	if(list->first != NULL)
	for (struct Element *e = list->first; e->next != NULL; e = list->first)
	{
		struct Element *buffer = e;
		list->first = list->first->next;
		free(buffer);
	}
	//letztes Element noch löschen
	free(list->first);
	list->first = NULL;
}

int printItem(struct Element* e)
{
	printf("%s: %d\n", e->datum, e->tagesproduktion);
}

int forall(struct List *list, ItemFunction exec)
{
	if (list->first != NULL)
		for (struct Element *e = list->first; e != NULL; e = e->next)
			exec(e);

}
