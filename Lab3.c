#include "stdio.h"
#include "math.h"


int main()
{
	double e = 0;
	double summ = 0; // сумма ряда
	double currentSum = 0; // текущий член ряда
	double x = 0;
	int i = 0;

	printf("Enter border e: ");
	scanf_s("%lf", &e);
	printf("Enter x: ");
	scanf_s("%lf", &x);


	while (currentSum < e)
	{
		currentSum = pow(-1.0, i)*pow(x,i) / factorial(i);
	
			summ += currentSum;
			i++;
	}

	printf("Sum of series %lf equals to %lf\n", e, summ);



double b = 0;
double e2 = 0;
double x2 = 0;
double summ2 = 0;
printf("Enter b for 2nd series");
scanf_s("%lf", &b);
printf("Enter border e for 2nd series");
scanf_s("%lf", &e2);
printf("Enter x for 2nd series");
scanf_s("%lf", &x2);
currentSum = 0;

while (currentSum < e2)
{
	currentSum = exp(-x2) + b;
	summ2 += currentSum;
}

printf("Sum of series %lf equals to %lf\n", e2, summ2);

_getch();
return 0;
}

int factorial(int n) //рекурсивное вычисление факториала
{
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}
