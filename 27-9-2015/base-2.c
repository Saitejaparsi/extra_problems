/*Proble: To find the binary like format if base is -2
Ex- consider 6 the normal binary format is 110 but if the base is -2 then 11010
Procedure:- first find the %2 of the number ...in that procedure .if we encunter a 1 at an odd position (starting from 0) then add the next appearing number with 1 and continue the procedure
Ex:- Consider 6 the normal binary format if base is 2 is 1 1 0
if base is -2 :- first we encounter 0 at '0' position then we get 1 at '1' which is odd position . so XOR the next appearing with 1. the next appeared bit
is 1 so add with 1 we get 1 0..so the format we got so far is 1010 but again we 1 (which is enterd at the last because of addition) so aggain add 1 to next
so the final format is 1 1 0 1 0 which is (16 -8 -2 == 6)*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void check(int a[50], int count, int itr, int tlen)
{
	int var1 = 0;

	while (itr < tlen)
	{
		var1 = 1;
		if (count == 0)
		{
			if (a[itr] == 0)
			{
				a[itr] = 0;
				itr++;
			}
			else
			{
				a[itr] = 1;
				if (itr % 2 == 1)
					count = 1;
				else
					count = 0;
				itr++;
			}
			var1 = 0;
		}
		if (count == 1 && var1 != 0)
		{
			if (a[itr] == 1)
			{
				a[itr] = 0;
				count = 1;
				itr++;
			}
			else if (a[itr] == 0 || a[itr] == '\0')
			{
				a[itr] = 1;
				count = 0;
				if (itr % 2 == 1)
					count = 1;
				itr++;
			}
			var1 = 1;
		}
	}
	printf("base:-2\n");
	for (var1 = itr - 1; var1 >= 0; var1--)
		printf("%d", a[var1]);

}
int rev(int a[50], int n)
{
	int var1 = 0, itr = 0, count = 0;
	while (n > 0)
	{
		var1 = n % 2;
		a[itr] = var1;
		n = n / 2;
		itr++;
	}
	a[itr] = 0;
	a[itr + 1] = 0;
	printf("\nactual binary (base:2) in reverse order\n");
	for (int i = 0; i < itr; i++)
		printf("%d", a[i]);
	return(itr);
}
void main()
{
	int a[50], count = 0, count1 = 0;
	int n;
	printf("enter number\n");
	scanf("%d", &n);
	if (n >= 0)
	{
		count1 = rev(a, n);		//to know the actual binary bits with base as 2 for the given number and count1 is length
		a[0] = a[0];
		printf("\n\n");
		if (count1 % 2 == 1)
			check(a, count, 1, count1 + 2);
		else
			check(a, count, 1, count1 + 1);
	}
	else
		printf("\n invalid number");
	getch();
}