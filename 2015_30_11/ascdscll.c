/*there is a sequence of ascending nodes and after that a sequences od descending nodes place in correct order
Procedure:first go upto that node untill ascending order ends.and from there and upto end reverse the list and attach it to the previous node*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct nde
{
	int data;
	struct node * link;
};
typedef struct nde node;

void rev(struct node **list)
{
	node *prev, *current, *nexte;
	prev = NULL;
	current = *list;
	nexte = current->link;
	while (current->link != NULL)
	{
		current->link = prev;
		prev = current;
		current = nexte;
		nexte = nexte->link;
	}
	current->link = prev;
	*list = current;
}
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
void ascdsc(node **h)
{
	node *temp1, *temp2, *p, *q, *pr=NULL;
	p = *h;
	q = p->link;
	while (p->link != NULL)
	{
		if (q->data > p->data)
		{
			pr = p;
			p = p->link;
			q = q->link;
		}
		else
			break;
	}
	rev(&p);
	pr->link = p;
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
	for (i = 0;i<n*2; i++)
		create(&head1);
	/*for (i = n * 2; i > n; i--)
		create(&head1, i);*/
	ascdsc(&head1);
	dis(head1);
	getch();
}