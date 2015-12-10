/*to find the last n lines of a file*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdarg.h>
void main()
{
	int y=0;
	int x=0;
	char c;
	FILE *fp = fopen("C:\\Users\\Prashanth\\Desktop\\abc.txt", "r");
	while ((c = fgetc(fp))!=EOF)
	{
		if (c == '\n')
		{
			x++;
		}
	}
	fclose(fp);
	FILE *fp1 = fopen("C:\\Users\\Prashanth\\Desktop\\abc.txt", "r");
	while ((c=fgetc(fp1))!=EOF)
	{
		if (c == '\n')
			y++;
		if (y>x-5)
		printf("%c", c);
		
	}
	getch();
}