/*problem is to find the multiplication of two numbers without using repetitve addition or '*' symbol
Procedure followed:done using bitwise operators,
conditions checked: whether numbers are -ve or +ve */
#include<stdio.h>
#include<conio.h>
int mul(int a, int b)
{
	int m = 0, x = 0, y = 0, c = 1;
	if (a < 0)					//checking whether numbers are negative or not
		x = -a;
	else x = a;
	if (b < 0)
		y = -b;
	else y = b;

	m = 0;
	while (y != 0)
	{
		if (y & 1)
		{
			m = m + x;
		}
		x = x << 1;
		y = y >> 1;
	}
	if ((a < 0 && b < 0) || (a>0) && (b>0))
		c = 1;
	else if ((a>0 && b < 0) || (a < 0 && b>0))
		c = 2;
	if (c == 1)
		return(m);
	if (c == 2)
		return(-m);
}
main()
{
	int a, b, result;
	printf("Enter:\n");
	scanf("%d%d", &a, &b);
	result = mul(a, b);
	printf("Result:%d", result);
	getch();
}