// Lab4_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

double find_exp(double x);
int factorial(const int n);
void number_or_not(int* number);
int users_filling();

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Ввведите значение x\n");
    double x = users_filling();
    printf("x = %lf \n", x);
    printf("exp = %lf", find_exp(x));
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
            printf("Вы можете вводить только числа\n");
            printf("Пожалуйста введите еще раз\n");
        }
    } while (wrong_n);
}

int users_filling()
{
    int element = 0;
    number_or_not(&element);
    return element;
}

double find_exp(double x)
{
    const int n = 2;
    double sum = 0.0;
    for (int i = 0; i <= n; i++)
    {
        sum += (pow(x,i)) / factorial(i);
    }
    return sum;
}

int factorial(const int n)
{
    int calc_factorial = 1;
    for (int i = 1; i <= n; i++)
        calc_factorial = calc_factorial * i;
    return calc_factorial;
}
