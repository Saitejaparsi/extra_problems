/* given a sorted array but at certain position the order will be missed find that position (and rest all will be 0's)
Procedure:- jump the positions in multples of 2.if the position exceeds then we will encounter a zero.so from there we have to move back*/
#include<stdio.h>
#include<conio.h>
int len(int a[100])
{
	int i = 1, j, p = i, s = i;					// p has previous value of i and s has value of p
	for (;;)
	{
		if (a[i] > a[i + 1] && a[i] > a[i - 1])
			return(i);
		else if (!(a[i] >= a[i + 1] && a[i] >= a[i - 1]) && a[i] != 0 && a[i] != '\0')
		{
			if (i%p == 0)
			{
				p = i;
				s = p;
			}
			i = i * 2;
		}
		else if (a[i] == 0 || a[i] == '\0' || a[i] < 0)
		{
			i = p + s / 2;
			s = s / 2;
			if (s < 2)
			{
				p = p / 2;
				s = p;
			}
		}
	}
}
void main()
{
	int a[100];
	int i, j, k;
	printf("enter total length\n");
	scanf("%d", &k);
	for (i = 0; i < k; i++)
		scanf("%d", &a[i]);
	j = len(a);
	printf("%d", j);
	getch();
}