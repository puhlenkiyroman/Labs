// Lab4_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

double find_exp(double x);
int factorial(const int n);
double get_elem();

int main()
{
    setlocale(LC_ALL, "Russian");

    double x = get_elem();
    printf("x = %lf \n", x);
    printf("exp = %lf", find_exp(x));
    return 0;
}

double get_elem()
{
    double elem;

    while (true)
    {
        cout << "Enter the element of array: ";
        cin >> elem;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "It's not correct, please write again" << endl;
        }
        else
        {
            return elem;
        }
    }
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
