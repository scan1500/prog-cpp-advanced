#include <iostream>
using namespace std;

void insert(int val);

struct Element
{
	int value;
	struct Element *preElement;
	struct Element *postElement;
}*position=NULL; //(globaler) Zeiger auf das aktuelle Kettenglied


void main()
{
	struct Element* p;
	int n;
	insert(1);
	insert(2);
	insert(3);
	position = position->preElement;
	insert(4);
	position = position->postElement;
	position = position->postElement;

	for (p = position, n = 0; n <= 4; p = p->postElement, n++)
		printf("%i -> ", p->value);

	system("pause");
}

void insert(int val)
{
	struct Element *e = (Element*)malloc(sizeof(struct Element));
	e->value = val;
	if (position == NULL)
	{
		position = e;
		position->postElement = NULL;
		position->preElement = NULL;
	}
	else if (position->postElement == NULL && position->preElement == NULL)
	{
		e->postElement = position;
		e->preElement = position;

		position->postElement = e;
		position->preElement = e;

		position = e;
	}
	else
	{
		e->postElement = position->postElement;
		e->preElement = position;

		position->postElement = e;
		position = e;
	}


}