// Lab3_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <limits>

using namespace std;

int get_elem();

int main()
{
	setlocale(LC_ALL, "Russian");
	int array[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {

			array[i][j] = get_elem();
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

int get_elem()
{
	int elem;

	while (true)
	{
		cout << "Enter the element of array: ";
		cin >> elem;
		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout <<"It's not correct, please write again" << endl;
		}
		else
		{
			return elem;
		}
	}
}
