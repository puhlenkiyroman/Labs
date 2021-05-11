#include <iostream>
#include <cmath>
using namespace std;

int Get_Number();
int GetNaturalNumberLessThanEleven();

class CalculateClass {
public:
    void set_x(double number) 
    {
        x = number;
    }

    static void set_n(int number) 
    {
        n = number;
    }

    double CalculateSeries() {
        double Sum = 0;
        for (int i = 0; i < n; i++) 
        {
            double Summand = (pow(x, 2 * i)) / (factorial(2 * i));
            Sum += Summand;
        }
        return Sum;
    }

    static int GetElementsCount() {
        return n;
    }

private:
    static int n;
    double x = 0;
        int factorial(int number) 
        {
            int res = 1;
            for (int i = 1; i <= number; i++) 
            {
                res *= i;
            }
            return res;
        }
};

int CalculateClass::n = 10;

int main()
{
    cout << "Enter the x for calculate ch(x): ";
    int x = Get_Number();
    CalculateClass Obj2;
    Obj2.set_x(x);
    cout << "Enter the count of sequence(in the range between 1 and 10) : ";
    int n = GetNaturalNumberLessThanEleven();
    CalculateClass::set_n(n);
    cout << "When x = " << x << ", when count of sequence = " << n << ", ch(x)  = " << Obj2.CalculateSeries() << "\n";
    return 0;
}


int Get_Number()
{
    while (true)
    {
        int number;
        cin >> number;
        if (cin.fail())
        {
            cout << "It's not a number\n";
            cout << "Enter the number again";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

int GetNaturalNumberLessThanEleven() {
    int number = 0;
    do {
        number = Get_Number();
        if (number < 1 || number > 10) 
        {
            cout << "Count of sequence must be in the range between 1 and 10\n" << endl;
            cout << "Enter the number again" << endl;
        }
    } while ((number < 1) || (number > 10));
    return number;
}