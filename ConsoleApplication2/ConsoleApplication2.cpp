#include <iostream>
using namespace std;

double F(double x)
{
    
    return x - 1/(3+sin(3.6*x));
}

double DF(double x)
{
    
    return 1 - 3.6 * (cos(3.6 * x) / ((sin(3.6 * x) + 3) * (sin(3.6 * x) + 3)));
}


double halfDivisionMethod(double left, double right, double eps)
{
    double x = (left + right) / 2; 
    while (abs(F(x)) > eps)
    {
        x = (left + right) / 2;
        ((F(left) * F(x) < 0) ? right : left) = x;
    }
    return x;
}

double newtonsMethod(double left, double right, double eps)
{
    double x = (left + right) / 2; 
    while (abs(F(x)) > eps)
    {
        x = x - (F(x) / DF(x));
    }
    return x;
}

double iterationMethod(double left, double right, double eps)
{
    double x1, x = (left + right) / 2; 
    
    do
    {
        x1 = x;
        x = 1 / (3 + sin(3.6 * x));
    } while (abs(x1 - x) > eps);
    return x;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout.setf(ios::fixed);
    cout.precision(6);

    double a = 0;
    double b = 0.85;
    double eps = 0.000001;

    cout << "Решение уравнения x - 1/(3+sin(3.6*x)) = 0" << endl;
    cout << "Левая граница " << a << ", правая " << b << ", точность " << eps << endl << endl;
    cout << "Решение уравнения методом половинного деления " << halfDivisionMethod(a, b, eps) << endl;
    cout << "Решение уравнения методом Ньютона " << newtonsMethod(a, b, eps) << endl;
    cout << "Решение методом итераций " << iterationMethod(a, b, eps) << endl;
}