/*Problem:To add two strings equal length without reversing the string and provided that starting 
Procedure:add the two digits of the same index .if it is less than 9 then mark that position(k) if it is gretaer than 9 then make all 0's upto 
position(k) and add 1 to the position k*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void add(char *a, char *b)
{
	int i, j = 0, k = 0, var = 0;
	for (i = 0; a[i] != '\0';)
	{
		k = a[i] - 48 + b[i] - 48;
		a[i] = a[i] + b[i] - 48;
		if (k < 9)
		{
			j = i;				// j has index value where sum is less than 9
			var = 0;
		}
		if (k > 9)
		{
			a[j] = a[j] + 1;
			for (var = j + 1; var <= i; var++)		//carry addition process
			{
				a[var] = '0' + (k % 10);
				b[var] = '0';
			}
			var = 1;
		}
		if (var == 1)
			i = i;
		else
			i = i + 1;
	}
	puts(a);
}
void main()
{
	char *a, *b;
	a = (char *)malloc(sizeof(char));
	b = (char *)malloc(sizeof(char));
	gets(a);
	gets(b);
	add(a, b);
	getch();
}