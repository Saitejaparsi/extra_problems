/*Circular linkeed lists addition of node*/
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
	while (p->link != h)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->", p->data);
	p = p->link;
	printf("%d", p->data);
}
void insf(node **head, int x)
{
	node *temp, *p;
	temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->link = NULL;
	if (*head == NULL)
	{
		*head = temp;
		(*head)->link = *head;
	}
	else
	{
		p = *head;
		while (p->link != *head)
			p = p->link;
		temp->link = *head;
		p->link= temp;
	    *head = temp;
	}
}
void insaf(node **head, int pos, int x)
{
	int i=0;
	node *temp,*p;
	temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->link = NULL;
	if (pos== 0)
	{
		insf(&head, x);
	}
	else if (*head == NULL)
	{
		*head = temp;
		(*head)->link = *head;
	}
	else
	{
		p = *head;
		while (p->link != *head&&i < pos)
		{
			p = p->link;
			i++;
		}
		temp->link = p->link;
		p->link = temp;
	}
}
void create(node **head, int x)
{
	node *temp, *p;
	temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->link = NULL;
	if (*head == NULL)
	{
		*head = temp;
		(*head)->link = *head;
	}
	else
	{
		p = *head;
		while (p->link != *head)
			p = p->link;
		temp->link = p->link;
		p->link = temp;
	}
}
void main()
{
	node *head = NULL;
	int n, i,pos,num;
	for (i = 0; i < 5; i++)
		create(&head, i);
	printf("Enter your option\n1)insert at first\n2)insert in middle");
	scanf("%d", &n);
	printf("\n enter number to insert:\n");
	scanf("%d", &num);
	switch (n)
	{
	case 1: insf(&head, num); break;
	case 2:printf("\n enter poisition\n");
		scanf("%d", &pos);
		if (pos < 0)
			printf("\n invalid position");
		else if (pos == 0)
			insf(&head, num);
		else
			insaf(&head, pos, num); break;
	default:printf("\n invalid option");
	};
	dis(head);
	getch();
}