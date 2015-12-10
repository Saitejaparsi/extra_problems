/* to print all the possible permutations of a number*/
#include<stdio.h>
#include<math.h>
unsigned long int permutation[100000];
int ind = 0;
void swap(int * digits, int i, int j)
{
	int temp = digits[i];
	digits[i] = digits[j];
	digits[j] = temp;
}
void permute(int *digits, int first, int last)
{
	unsigned long int num = 0;
	int x = 0;
	if (first == last)
	{
		for (x = 0; x < last; x++)
			num = 10 * num + digits[x];
		//printf("%d\n",num);
		permutation[ind] = num;
		ind++;
		//printf("\n%d",num);
		return;
	}
	permute(digits, first + 1, last);
	//printf("%d\n", first + 1);
	for (int i = first + 1; i < last; i++)
	{
		if (digits[first] == digits[i])
			continue;
		swap(digits, first, i);
		permute(digits, first + 1, last);
		swap(digits, first, i);
	}
}
void qsort(int first, int last)
{
	int pivot, j, i, temp;
	if (first<last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i<j)
		{
			while (permutation[i] <= permutation[pivot] && i<last)
				i++;
			while (permutation[j]>permutation[pivot])
				j--;
			if (i<j)
			{
				temp = permutation[i];
				permutation[i] = permutation[j];
				permutation[j] = temp;
			}
		}
		temp = permutation[pivot];
		permutation[pivot] = permutation[j];
		permutation[j] = temp;
		qsort(first, j - 1);
		qsort(j + 1, last);
	}
}


int main()
{
	int np = 0, rev = 0, temp = 0, digits[10], i = 0;
	printf("Enter a number :");
	scanf("%d", &np);
	while (np != 0)
	{
		digits[i] = np % 10;
		np = np / 10;
		i++;
	}
	permute(digits, 0, i);
	qsort(0, ind - 1);
	for (int k = 0; k<ind; k++)
		printf("%d\n", permutation[k]);
	printf("\n");
	getch();
}
