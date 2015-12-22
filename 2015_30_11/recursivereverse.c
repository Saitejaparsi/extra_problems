#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct nde
{
	int data;
	struct node * link;
};
typedef struct nde node;
void dis(node *h)
{
	node *p;
	p = h;
	while (p->link != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->", p->data);
}
void create(node **head)
{
	int x;
	scanf("%d", &x);
	node *temp, *p;
	temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->link = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		p = *head;
		while (p->link != NULL)
			p = p->link;
		p->link = temp;
	}

}
void recursiveReverse(node ** h)
{
	node * first;
	node * remain;
	node *extra;
	if (*h == NULL)
		return;
	first = *h;
	remain = first->link;
	if (remain == NULL)
		return;
	recursiveReverse(&remain);
	extra = first->link;
	extra->link = first;
	first->link = NULL;
    *h = remain;
}
void main()
{
	node *head = NULL;
	int n, i, pos, num;
	printf("\n enter list length");
	scanf("%d", &n);
	if (n > 0)
	{
		for (i = 0; i < n; i++)
			create(&head);
		recursiveReverse(&head);
		dis(head);
	}
	else
		printf("invalid length");
	getch();
}