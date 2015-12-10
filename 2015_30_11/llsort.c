/*To sort a sorted list where 1 element is misplaced
Procedure: first finding the element where its previous number is bigger than that.marking that position and checking further for the exact number
to be replaced and then swapping*/
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
    scanf("%d",&x);
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
void sort(node **head)
{
	int i,j;
	node *temp,*p,*q,*r;
	p = *head;
	q = p;
	while (p->link != NULL&&p->data >= q->data)
	{
		q = p;
		p = p->link;
	}
	i = q->data;
	temp = q;
	r = p;
	p = p->link;
	while (p->link != NULL&&p->data >= r->data)
	{
		r = p;
		p = p->link;
	}
	j = p->data;
	p->data = i;
	q->data = j;
}
void main()
{
	node *head = NULL;
	int n, i, pos, num;
	printf("\n enter list length");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	create(&head);
	sort(&head);
	dis(head);
	getch();
}