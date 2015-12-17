/* conversion of a decimal number to binary and then to octal number*/
#include<stdio.h>
#include<conio.h>
void conv(int n)
{
	int rem, itr = 0, temp = 0, var1, var2;
	int a[100];
	while (n > 0)		//conversion to binary
	{
		var1 = n % 2;
		a[itr] = var1;
		n = n / 2;
		itr++;
	}
	var1 = itr;
	var2 = var1;
	var1 = 0;
	temp = 0;
	for (itr = 0; itr < var2; itr++)			//coversion to octal
	{
		if (itr % 3 == 0)						//as in octal set of 3 bits are considered
			rem = 1;
		if (itr % 3 == 1)
			rem = 2;
		if (itr % 3 == 2)
			rem = 4;
		temp = a[itr] * rem + temp;
		//printf("%d ", temp);
		a[var1] = temp;

		if (itr % 3 == 2)						//afetr 3 bits are considered as a single one in octal,so after 3 bits incrementing the var1(itrator) value
		{
			var1++;
			temp = 0;
		}
	}
	if (itr % 3 == 0)
		var1 = var1 - 1;
	printf("\noctal\n");
	for (itr = var1; itr >= 0; itr--)			//printing the octal values
		printf("%d", a[itr]);
}
void main()
{
	int n;
	printf("enter number\n");
	scanf("%d", &n);
	if (n >= 0)
		conv(n);
	else
		printf("invalid number");
	getch();
}