/* conversion of a decimal number to octal number*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void conv(int n)
{
	int x, i = 0, temp = 0, j, b;
	int a[100];
	while (n > 0)		//conversion to binary
	{
		j = n % 2;
		a[i] = j;
		n = n / 2;
		i++;
	}
	j = i;
	b = j;
	j = 0;
	temp = 0;
	for (i = 0; i < b; i++)			//coversion to octal
	{
		if (i % 3 == 0)
			x = 1;
		if (i % 3 == 1)
			x = 2;
		if (i % 3 == 2)
			x = 4;
		temp = a[i] * x + temp;
		//printf("%d ", temp);
		a[j] = temp;

		if (i % 3 == 2)
		{
			j++;
			temp = 0;
		}
	}
	if (i % 3 == 0)
		j = j - 1;
	printf("\noctal\n");
	for (i = j; i >= 0; i--)
		printf("%d", a[i]);
}
void main()
{
	int n;
	printf("enter number\n");
	scanf("%d", &n);
	conv(n);
	getch();
}