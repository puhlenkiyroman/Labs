// Lab3_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;
void number_or_not(int* number);
int users_filling();
int main()
{
	setlocale(LC_ALL, "Russian");
	int array[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {

			array[i][j] = users_filling();
		}
	}

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			printf("%d \t", array[x][y]);
		}
		printf("\n");
	}

	int a = 1;
	int b = -array[0][0] - array[1][1];
	int c = array[0][0]*array[0][1] - array[0][1] * array[1][0];
	if ((b * b - 4 * a * c) >= 0)
	{
		int x1 = (-1*b + sqrt(b*b - 4*a*c)) / (2*a);
		printf("x1 = %d\n", x1);
		int x2 = (-1*b - sqrt(b*b - 4*a*c)) / (2*a);
		printf("x2 = %d\n", x2);
	}
	else
	{
		printf("Нет корней");
	}
	return 0;
}

void number_or_not(int* number)
{
	int wrong_n = 0;
	do {
		const int value_n = scanf_s("%d", number);
		wrong_n = (value_n != 1);
		getchar();
		if (wrong_n)
		{
			printf("You can type only the numbers.");
			printf("Please enter again: ");
		}
	} while (wrong_n);
}

int users_filling()
{
	int element = 0;
	printf("Enter the element of array: ");
	number_or_not(&element);
	return element;
}
