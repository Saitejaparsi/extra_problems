#include<stdio.h>
#include<conio.h>
void fib(int x)
{
	int j, f = 0, s = 1, t[32], i = 0, sum = 0, fin[32],z=0;
	for (i = 0; i < 32; i++)
	{
		t[i] = 0;
	fin[i] = 0;
	}
	t[0] = 1;
	i = 1;
	while (t[i-1] < x)
	{
		t[i] = f + s;
		f = s;
		s = t[i];
		i++;

	}
	s = i;
	for (j = 0; j < i;j++)
	printf("%d ", t[j]);
	for (j=0;j<i;j++)
	{
		fin[j] = 1;
		sum = t[j]*fin[j] + sum;
		if (sum == x)
		{
			break;
		}
		if (sum>x)
		{
			fin[j-1] = 0;
			//printf("%d\n", j - 1);
			x= x-t[j];
			sum = 0;
			j = -1;
		}
	}
	//printf("\n%d", a[1]);
	printf("\n");
	for (i = 0; i <s; i++)
		printf("%d ", fin[i]);
}
void main()
{
	int x;
	printf("\nenter the number");
	scanf("%d", &x);
	if (x > 0)
		fib(x);
	else
		printf("\n not possible");
	getch();
}