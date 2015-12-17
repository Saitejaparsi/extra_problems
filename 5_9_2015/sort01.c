/*sort 0 1 in an array given that array has only 0's and 1's*/
#include<stdio.h>
#include<conio.h>
void sort1(int a[100], int len, int len0)
{
	int itr;
	for (itr = 0; itr < len0; itr++)
		a[itr] = 0;
	for (itr = len0; itr < len; itr++)
		a[itr] = 1;
}
void sort2(int a[100], int len)
{
	int itr1 = 0, itr2= len;
	while (itr1<itr2)
	{

		if ((a[itr1] == 1) && (a[itr2] == 0))
		{
			a[itr1] = 0;
			a[itr2] = 1;
			itr1++;
			itr2--;
		}
		else if (a[itr1] != 1)
			itr1++;
		else if (a[itr2] != 0)
			itr2--;
	}
}
void sort3(int a[100], int len, int sum)
{
	int itr;
	for (itr = 0; itr <len - sum; itr++)
		a[itr] = 0;
	for (; itr < len; itr++)
	{
		a[itr] = 1;
	}
}
void main()
{
	int len,a[100], itr, count = 0, sum = 0;		//len is total length of the array
	printf("enter array length\n");
	scanf("%d", &len);
	if (len> 0)
	{
		printf("enter array elements\n");
		for (itr = 0; itr < len; itr++)
		{
			scanf("%d", &a[itr]);
			sum = sum + a[itr];
			if (a[itr] == 0)
				count = count + 1;
		}
		sort1(a, len, count);		
		printf("\nmethod-1:");                        //sorting method 1 (here count is no.of 0's in array)
		for (itr = 0; itr < len; itr++)
			printf("%d", a[itr]);
		printf("\n");
		sort2(a, len);									//sorting method 2
		printf("method-2:");
		for (itr = 0; itr < len; itr++)
			printf("%d", a[itr]);
		printf("\n");
		sort3(a, len, sum);								//sorting method 3
		printf("method-3:");
		for (itr = 0; itr < len; itr++)
			printf("%d", a[itr]);
	}
	else
		printf("array does not exists");
	getch();

}