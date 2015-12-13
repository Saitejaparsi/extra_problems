#include<stdio.h>
#include<conio.h>
void sum1(int *a, int n)
{
	int i = 0, j = 0, sum = 0, max = 0, k = 0, index = 0, alt = 0;
	int left[10], right[10];
	for (i = 0; i < n; i++)
	{
		left[i] = 0;
		right[i] = 0;
	}
	printf("\n enter length");
	scanf("%d", &k);
	for (i = 0; i < n; i++)
	{
		alt = i;
		for (j = 0; j < k / 2; j++)
		{
			if (alt > 0)
				left[i] = a[alt - 1] + left[i];
			else
				left[i] = 0+left[i];
			alt--;
		}
	}
	for (i = 0; i < n; i++)
	{
		alt = i;
		for (j = 0; j < k / 2; j++)
		{
			if (alt+1 <n)
				right[i] = a[alt + 1] + right[i];
			else
				right[i] = 0 + right[i];
			alt++;
		}
	}
	for (i = 0; i < n; i++)
	{
		right[i] = a[i] + left[i] + right[i];
		if (max < right[i])
		{
			max = right[i];
			index = i;
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", right[i]);
	printf("\nwinner=%d at index= %d", a[index], index);
}
void main()
{
	int a[10];
	int i,n;
	printf("enter size\n");
	scanf("%d", &n);
	printf("\n enter list");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sum1(a,n);
	getch();
}