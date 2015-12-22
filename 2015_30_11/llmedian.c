/*median of a sorted list*/
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
	node *p,*q;
	p = h;
	q = h;
	int i = 0,x=0;
	while (p->link != NULL)
	{
		p = p->link;
		i++;
	}
	if ((i-1) % 2 == 1)
	{
		while (q->link != NULL&& x != i / 2)
		{
			x = x + 1;
			q = q->link;
		}
		printf("median=%d", q->data);
	}
	else
	{
		while (q->link != NULL&& x != (i-1) / 2)
		{
			x = x + 1;
			q = q->link;
		}
		printf("median=%d", q->data);
		if (q->link != NULL)
			q = q->link;
		printf(",%d", q->data);
	}
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
void main()
{
	node *head1 = NULL;
	int n, i;
	printf("enter length\n");
	scanf("%d", &n);
	if(n>0)
	{
	for (i = 0;i<n ; i++)
		create(&head1);
	dis(head1);
	}
	else
	printf("invalid length");
	getch();
}