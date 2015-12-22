/*adding two lists
procedure:reverse the lists and then add and again reverse the o/p list*/
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
int create(node **head)
{
	node *temp, *varpointer;
    int data1;
	scanf("%d", &data1);
	if (data1 > -1 && data1 <10)
	{
		temp = (node*)malloc(sizeof(node));
		temp->data = data1;
		temp->link = NULL;
		if (*head == NULL)
		{
			*head = temp;
		}
		else
		{
			varpointer = *head;
			while (varpointer->link != NULL)
				varpointer = varpointer->link;
			varpointer->link = temp;
		}
		return 0;
	}
	else{
		printf("value not allowed enter again\nnumber should be >-1 and <10\n");
		return 1;
	}
}
void dis(node *h)
{
	node *pointer;
	pointer = h;
	while (pointer->link != NULL)
	{
		printf("%d", pointer->data);
		pointer = pointer->link;
	}
	printf("%d", pointer->data);
}
void add(node **h1, node **h2)
{
	node *temp,*p,*q,*r,*f1,*f2;
	p = *h1;
	q = *h2;
	f1 = (*h1)->link;
	f2 = (*h2)->link;
	int count=0, sum=0,sum2=0;
	while (p->link != NULL&&q->link != NULL)
	{
		sum = p->data + q->data+count;
		if (sum > 9)
		{
			count = 1;
			if (f1->link == NULL||f2->link==NULL)
			sum2 = sum;
			sum = sum % 10;
		}
		else
			count = 0;
		r = p;
		p->data = sum;
		p = p->link;
		q = q->link;
	}
	while (p->link != NULL)   //for remaining  elements in list
	{
		if (count > 0)
		{
			p->data = p->data + count;
			sum = p->data;
			if (sum > 9)
			{
				p->data = sum % 10;
				count = sum / 10;
			}
			else
				count = 0;
		}
		r = p;
		p = p->link;
	}
	if (sum > 9)
		r->data = sum2+r->data;

}
void xtranode(node **h)   //creating an extra dummy node at the end so we can access all the original nodes
{
	node *temp, *p;
	temp = (node*)malloc(sizeof(node));
	temp->link = NULL;
	temp->data = 0;
	p = *h;
	while ((p)->link != NULL)
	{
		p = (p)->link;
	}
	(p)->link = temp;
}
void main()
{
	node *head1 = NULL, *head2 = NULL;
	int n, i, pos, num, n1, n2, r,var=0;
	printf("enter list1 length n1\n");
	scanf("%d", &n1);
	printf("enter list2 length n2\n");
	scanf("%d", &n2);
	if (n1 > 0 && n2 > 0)
	{
		printf("\n enter list1\n");
		for (i = 1; i <= n1; i++)
		{
			var=create(&head1);
				if(var==1)
					i = i - 1;
		}
		printf("\n enter list2\n");
		for (i = 1; i <= n2; i++)
		{
			var=create(&head2);
			if (var == 1)
				i = i - 1;
		}
		if (n1 > 0 && n2 > 0)
		{
			rev(&head1);
			rev(&head2);
			xtranode(&head1);
			xtranode(&head2);

			if (n1 >= n2)
			{
				add(&head1, &head2);
				rev(&head1);
				dis(head1);
			}
			else
			{
				add(&head2, &head1);
				rev(&head2);
				dis(head2);
			}
		}
	}
	else
		printf("length cannot be empty or negative");
	getch();
}