// Lab1_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.   \
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double V, H, t, T, x, y, value_sin;
    int alpha;
    double g = 9.8;

    printf("Введите значение времени t\n");
    int count_of_t = scanf_s("%lf", &t);
    if (t < 0 || count_of_t != 1)
    {
        cout << "Ввведенное значение времени или отрицательное, или не является числом\n";
        return -1;
    }
    else {}
    printf("Введите значение скорости V\n");
    int count_of_V = scanf_s("%lf", &V);
    if (V < 0 || count_of_V != 1)
    {
        cout << "Ввведенное значение скорости или отрицательное, или не является числом\n";
        return 0;
    }
    else {}
    printf("Введите значение угла alpha\n");
    int count_of_alpha = scanf_s("%d", &alpha);
    if (alpha < 0 || count_of_alpha != 1)
    {
        cout << "Ввведенное значение угла или отрицательное, или не является числом\n";
        return 0;
    }
    else {}
    printf("Введите значение высоты обрыва H\n");
    int count_of_H = scanf_s("%lf", &H);
    if (H < 0 || count_of_H != 1)
    {
        cout << "Ввведенное значение высоты обрыва или отрицательное, или не является числом\n";
        return 0;
    }
    else {}
    value_sin = sin(alpha);
    x = V * t * cos(alpha);
    y = H + V * t * value_sin - g * (t * t) / 2;
    T = ((V * value_sin) / g) * (1 + (sqrt(1 + (2 * g * H) / (V * V * value_sin * value_sin))));
    double answer = T < 0 ? t : T;
    if (answer < 0)
    {
        cout << "Камень недостиг дна";
    }
    else
    {
        cout << "Значение T = " << answer;
    }
    return 0;
}
