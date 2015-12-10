/*Question 5
Procedure.First consider a list and compare it with other.if the other list data is less to the 1st one then add that node to 1st list and so on upto end
while finding out the position we need to traverse upto r and return the rth node*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct nde
{
int data;
struct node * link;
};
typedef struct nde node;
void insaf(node **h, int data1,int itr) //inserting a node after certain point
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
void mergmethd2(node **h1, node **h2)
{
node *pointerh1, *pointerh2,*prev;
int i = 0,j=0,k=0;
pointerh1 = *h1;
pointerh2 = *h2;
prev = *h1;
while (pointerh1->link != NULL&&pointerh2->link != NULL)  //comparing until both list size is same
{
	k = 1;
if (pointerh1->data < pointerh2->data)
{
pointerh1 = pointerh1->link;
i=i+1;
}
else if (pointerh1->data > pointerh2->data)
{
j = pointerh2->data;
insaf(&prev, j,i);                                         //inserting a node in between 
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
while (pointerh2->link != NULL)  //if h1 size is less than h2
{
	i = i + 1;
	j = pointerh2->data;
	insaf(&prev, j, i);          //inserting remaining nodes
	pointerh2=pointerh2->link;
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
void create(node **head)
{
node *temp, *varpointer;
int x;
scanf("%d", &x);
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
void xtranode(node **h)   //creating an extra dummy node at the end so we can access all the original nodes
{
	node *temp, *p;
	temp= (node*)malloc(sizeof(node));
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
node *head1 = NULL,*head2=NULL;
int n, i, pos, num,n1,n2;
printf("\nenter list1 size\n");
scanf("%d", &n1);
if (n1 <= 0)
printf("list not possible");
else{
	printf("enter list 1\n");
	for (i = 1; i <= n1; i++)
		create(&head1);
}
printf("\nenter list2 size\n");
scanf("%d", &n2);
if (n2<=0)
printf("list not possible");
else{
	printf("enter list 2\n");
	for (i = 1; i <= n2; i++)
		create(&head2);
}
xtranode(&head2);
mergmethd2(&head1, &head2);
dis(head1);
getch();
}