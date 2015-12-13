/*Problem to find out magic number exists or not in a  given number of digits
in maths there is direct formula to find this out i.e., in n(no.of digis) is multiple of 6 then ((10 power 6)-1)/7 gives the magic number*/
#include<stdio.h>
#include<conio.h>
void magic(int n)
{
	long double l=1;
	int i;
	if (n > 0 && n % 6 == 0)
	{
		printf("\n magic number exists");
		for (i = 0; i < n; i++)
		{
			l = l * 10;
		}
		l = (l - 1) / 7;
		printf("\n%lf", l);
		printf("proof for this");
		for (i = 2; i <7; i++)
			printf("\n%lf*%d=%lf",l,i, l*i);
	}
	else
		printf("\nmagic number doesnot exists");
}
void main()
{
	int n;
	printf("enter no.of digits\n");
	scanf("%d", &n);
	magic(n);
	getch();
}