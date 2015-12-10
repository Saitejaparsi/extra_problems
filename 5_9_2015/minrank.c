/*Problem is to find the min rank of a number in its sorted order permutations (repetition of numbers is allowed)
Procedure : consider a number 3214 . lets take its 1st number i.e., 3.. the number of digits which are less to it in its right side are 2
and no.of digits to its right side are 3 so possible permutations are 2*3! + next consider 2.no.of digits less to it on its right side are 1 and no of digits to its right sde
are 2 so 1*2!+ now consider 1 no.of digits right to it are 1 and less than that is 0 so 0*1!.
so total 2*3!+1*2!+0*1!=14 .therefore rank of 3214 is 14.
the same logic is applicable if there are repetitions of a number.for that we need to fnd how many digits are repeated in its right side and then divide with that*/
#include<stdio.h>
#include<conio.h>
int fact(int x)
{
	int i, fact = 1;
	if (x == 0 || x == 1)
		return(1);
	for (i = 1; i <= x; i++)
		fact = fact*i;
	return(fact);
}
void permutation(int p)
{
	int x, i, a[20], s = 0, j, count = 0;
	int n = 0, k = 0, temp = 0, result = 0;
	int counts[10], as = 1;
	x = 0;
	k = p;
	while (k > 0)                                       //storing the number into an array
	{
		s = k % 10;
		a[x] = s;
		x++;
		k = k / 10;
	}
	n = x;                                              //n is length of the array
	for (i = 0; i < x / 2; i++)                         //reversing the array
	{
		temp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = temp;
		n = n - 1;
	}
	for (i = 0; i < 9; i++)
		counts[i] = 0;
	k = x;                                               //k is total numbers right to the 1st digit
	for (i = 0; i < x; i++)
	{
		for (j = i + 1; j < x; j++)
		{
			if (a[i]>a[j])
			{
				count = count + 1;					//to know how many numbers are lesser than that specific number which are on right side of it
			}
		}
		for (j = i; j < x; j++)
		{
			counts[a[j]] = counts[a[j]] + 1;			//to know how many numbers are repeated (a hash table like)
		}
		for (n = 0; n < 9; n++)
		{
			if (counts[n] >= 1)
			{
				as = as* (fact(counts[n]));		//counting the factorial of no.of repetitions like example 2!*3! etc
			}
		}
		for (n = 0; n < 9; n++)
		{
			counts[n] = 0;
		}
		result = result + ((count*fact(k - 1)) / as);         // k is total no.of digits right side to that particular number
		k = k - 1;
		count = 0;
		as = 1;
	}
	printf("%d", result);
}
void main()
{
	int  n = -1;
	scanf("%d", &n);
	if (n > -1)					//for checking invalid characters like a,b,c
		permutation(n);
	else
		printf("invalid");
	getch();
}