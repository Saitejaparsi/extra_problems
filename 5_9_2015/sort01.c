/*sort 0 1 in an array given that array has only 0's and 1's*/
#include<stdio.h>
#include<conio.h>
void sort1(int a[100], int n, int x)
{
	int i;
	for (i = 0; i < x; i++)
		a[i] = 0;
	for (i = x; i < n; i++)
		a[i] = 1;
}
void sort2(int a[100], int n)
{
	int i = 0, j = n;
	while (i<j)
	{

		if ((a[i] == 1) && (a[j] == 0))
		{
			a[i] = 0;
			a[j] = 1;
			i++; j--;
		}
		else if (a[i] != 1)
			i++;
		else if (a[j] != 0)
			j--;
	}
}
void sort3(int a[100], int n, int sum)
{
	int i;
	for (i = 0; i <n - sum; i++)
		a[i] = 0;
	for (; i < n; i++)
	{
		a[i] = 1;
	}
}
void main()
{
	int n, a[100], i, count = 0, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum = sum + a[i];
		if (a[i] == 0)
			count = count + 1;
	}
	sort1(a, n, count);
	for (i = 0; i <n; i++)
		printf("%d", a[i]);
	printf("\n");
	sort2(a, n);
	for (i = 0; i <n; i++)
		printf("%d", a[i]);
	printf("\n");
	sort3(a, n, sum);
	for (i = 0; i <n; i++)
		printf("%d", a[i]);

	getch();

}