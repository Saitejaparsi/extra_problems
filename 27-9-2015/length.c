/* given a sorted array but at certain position the order will be missed find that position (and rest all will be 0's)
Procedure:- jump the positions in multples of 2.if the position exceeds then we will encounter a zero.so from there we have to move back
this preocedure is followed inorder to reduce the complexity from that of traditional search as we require les no.of comparisions*/
#include<stdio.h>
#include<conio.h>
int len(int a[100])
{
	int itr1 = 1, prev = itr1, secprev = itr1;					// prev has previous value of itr1 and secondprev has value of prev(ious)
	for (;;)
	{
		if (a[itr1] > a[itr1 + 1] && a[itr1] > a[itr1 - 1])
			return(itr1);
		else if (!(a[itr1] >= a[itr1 + 1] && a[itr1] >= a[itr1 - 1]) && a[itr1] != 0 && a[itr1] != '\0')
		{
			if (itr1%prev == 0)
			{
				prev = itr1;
				secprev = prev;
			}
			itr1 = itr1 * 2;
		}
		else if (a[itr1] == 0 || a[itr1] == '\0' || a[itr1] < 0)
		{
			itr1 = prev + secprev / 2;
			secprev = secprev / 2;
			if (secprev < 2)
			{
				prev = prev / 2;
				secprev = prev;
			}
		}
	}
}
void main()
{
	int a[100];
	int itr1, reqlength, totalength;
	printf("enter total length\n");
	scanf("%d", &totalength);
	if (totalength > 0)
	{
		if (totalength > 1)
		{
			for (itr1 = 0; itr1 < totalength; itr1++)
				scanf("%d", &a[itr1]);
			reqlength = len(a);
			printf("The position upto which ascending order is preseent is :%d", reqlength);
		}
		else
			printf("The position upto which ascending order is preseent is :0 as only one exists");
	}
	else
		printf("array does not exists because length is <=0");
	getch();
}