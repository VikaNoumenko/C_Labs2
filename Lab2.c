#include "stdio.h"
#include "math.h"



int factorial(int n);

int main()
{

	int a[10] = { 5, 4, 3, 2, 1, 10, 9, 8, 7, 6 };

	
	printf("ARRAY: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	int A = 0, B = 0; // ������������� ���������

	printf("ENTER A: ");
	scanf_s("%d", &A);
	printf("ENTER B: ");
	scanf_s("%d", &B);

	int amount = 0; // c������ ��� �������� ���������� ��������� � ���������

	for (int i = 0; i < 10; i++)
	{
		if (a[i] == A)
		{
			while (a[i] != B && i < 10)// ������������ ��������, ���� �� ����� �� ������ �������
			{
				i++;
				amount++;
			}
			amount++;
			break;
		}
	}

	printf("Quantity of elements  in interval FROM %d TO %d = %d\n", A, B, amount);

	int sum = 0; // ���������� ��� �������� ����� ��������� ����� �������������
	int max = 0; // ��������� ���������� ��� �������� ���� ��������
	int max_index = 0; // ���������� ��� ����������� ������� ������������� ��������
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			max_index = i;
		}
	}

	if (max_index == 9)
	{
		printf("MAX ELEMENT IS THE LAST IN AN ARRAY\n");
	}
	else {
		for (int i = max_index + 1; i < 10; i++)
		{
			sum += a[i];
		}

		printf("MAX ELEMENT = %d. SUM OF ELEMENTS AFTER MAX = %d\n", max, sum);
		_getch();
	}
}