/*merging two sorted lists*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct nde
{
	int data;
	struct node * link;
};
typedef struct nde node;
void insaf(node **h, int data1,int itr)
{
	node *temp1, *temp;
	int i = 0;
	temp = (node*)malloc(sizeof(node));
	temp->data = data1;
	temp->link = NULL;
	if (*h == NULL)
	{
		*h = temp;
	}
	else
	{
		temp1 = *h;
		while (temp1->link != NULL&&i < itr-1)
		{
			temp1 = temp1->link;
			i++;
		}
		temp->link = temp1->link;
		temp1->link = temp;
	}
}
void mergmethd2(node **h1, node **h2, int r)
{
	node *pointerh1, *pointerh2,*prev;
	int i = 0,j=0;
	pointerh1 = *h1;
	pointerh2 = *h2;
	prev = *h1;
	while (pointerh1->link != NULL&&pointerh2->link != NULL)
	{
		if (pointerh1->data < pointerh2->data)
		{
			pointerh1 = pointerh1->link;
			i=i+1;
		}
		else if (pointerh1->data > pointerh2->data)
		{
			j = pointerh2->data;
			insaf(&prev, j,i);
			pointerh2 = pointerh2->link;
			i = i + 1;
		}
		else if (pointerh1->data==pointerh2->data)
		{
			pointerh1 = pointerh1->link;
			pointerh2 = pointerh2->link;
			i = i + 1;
		}
	}
}
void dis(node *h,int r)
{
	node *pointer;
	pointer = h;
	int i = 0;
	while (pointer->link != NULL&&i!=r)
	{
		pointer = pointer->link;
		i++;
	}
	printf("\n%d", pointer->data);
}
void create(node **head, int x)
{
	node *temp, *varpointer;
	temp = (node*)malloc(sizeof(node));
	temp->data = x;
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
}
void main()
{
	node *head1 = NULL,*head2=NULL;
	int n, i, pos, num,n1,n2,r;
	printf("enter n1\n");
	scanf("%d", &n1);
	printf("enter n2\n");
	scanf("%d", &n2);
	printf("enter r\n");
	scanf("%d", &r);
	for (i = 1; i <= r*2; i++)
		create(&head1, n1*i);
	printf("\n");
	for (i = 1; i <= r*2; i++)
		create(&head2, n2*i);
	mergmethd2(&head1, &head2, r);
	dis(head1,r);
	getch();
}*/