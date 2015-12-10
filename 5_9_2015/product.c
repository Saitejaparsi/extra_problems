/*Problem: to find the procut of numbers in an array except that particular number.
Ex:-1) in array 1 2 3 4 5 the o/p shuld be 120 60 40 30 24 
Ex:-2) 0 1 2 3 4 o/p 24 0 0 0 0
Prcedure: take a left matrix lm and right matrix rm.
In left matrix store the product from last index ie 120 120 60 20 5
In right matrix store the product from first index ie 1 2 6 24 120
now the o/p matrix should be 120  60*1 20*2 5*6 24 == 120 60 40 30 24
*/
#include<stdio.h>
#include<conio.h>
void facts(int a[50], int b[50], int n)                                   // a is the input array
{                                                                        // b is the output array and left matrix
	int i, l = 1, x = 0, rm[50], c = 1, s = 1;;
	for (i = n - 1; i >= 0; i--)
	{
		b[i] = b[i] * a[i] * c;
		c = b[i];
		rm[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		rm[i] = rm[i] * a[i] * s;
		s = rm[i];
	}
	b[0] = b[1];
	for (i = 1; i < n; i++)
	{
		b[i] = rm[i - 1] * b[i + 1];
	}
	b[i - 1] = rm[n - 2];
}
void main()
{
	int a[50], b[50], n, i;
	printf("enter size\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = 1;
	}
	facts(a, b, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
	getch();
}