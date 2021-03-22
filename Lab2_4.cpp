// Lab2_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double x, sum = 0.0;
    const int n = 100;
    printf("Ввведите значение |x| < 1 : ");
    int count_of_x = scanf_s("%lf", &x);
    if (count_of_x != 1 || x >= 1)
    {
        printf("Вы ввели не число или оно больше, либо равно единице");
        return 0;
    }
    else {}
    x = fabs(x);
    for (int i = 0; i <= n; i++)
    {
        sum = sum + (pow(-1, i) * (i + 1) * pow(x, i));
    }
    cout << "Значение вычисленного ряда равняется " << sum;
    return 0;
}
