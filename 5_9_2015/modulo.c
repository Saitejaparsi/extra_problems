/*Problem is to find the modulus of power of a number
Procedure : storing squares of a modulo of the number into an array and then checking upto the given power
ex: consider 2 pow 3 modulo 3. first find 2 modulo 3 whilch is 2 ...store it into an array then square the result (i.e, 4) and find modulo of it which is 1 stroe it in array and so on.
so we get 2 ,1,1,1...etc ..these all are in powers of 2 i.e., we get sequence of powers as 1,2,4,8..etc so inorder to find power of 3 we will multiply power of 1 * power of 2 (as a pow m * a pow n = a pow m+n)
which is 2*1 . if we find the moudlo of this we will get the required moudulo . therefore 2 pow 3 modul 3 = 2*1 modulo 3 == 2 (as 8% 3 ==2)
Conditions checked : as the power or base cannot be negative in order to find the correct modulo,the numbers are verified whetehr they are +ve or not */
#include<stdio.h>
#include<conio.h>
void power(int x, int y, int a)
{
	int i = 1, f = 1, s, z = 1, b[20], m = 1;
	s = x%a;
	b[0] = s;
	s = b[0];
	while (m < y)
	{
		b[i] = (s*s) % a;					//storing the modulo of square powers of a number
		m = m * 2;
		s = b[i];
		i++;
	}
	i = 0;
	while (y > 0)
	{
		f = y % 2;							//for considering the power as a sum using
		if (f == 1)
		{
			z = (b[i] * z) % a;
		}
		i++;
		y = y / 2;
	}
	printf("remainder=%d", z);
}
void main()
{
	int x, y, a;
	printf("enter base");
	scanf("%u", &x);
	printf("enter power");
	scanf("%u", &y);
	printf("enter mod");
	scanf("%u", &a);
	if (x < 0 || y < 0 || a < 0)
		printf("invalid");
	else
		power(x, y, a);
	getch();
}