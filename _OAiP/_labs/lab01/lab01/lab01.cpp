#include <iostream> 

using namespace std;

double fun1(double x);
double fun2(double x);
void dih(double (*fun)(double), double a, double b);

void main(){
    double a, b;
    cout << "a, b: ";
    cin >> a >> b;
    dih(fun1, a, b);
    dih(fun2, a, b);
}

double fun1(double x) { return pow(x, 3) + 2 * x - 4; }
double fun2(double x) { return pow(x, 2) - 1; }

void dih(double (*fun)(double), double a, double b){
    double x = 0, e = 0.0001, l = 0;
    while (abs(a - b) > 2 * e){
        x = (a + b) / 2;
        l = (*fun)(a) * (*fun)(x);
        if (l <= 0) b = x;
        else a = x;
    } 
    cout << "result = " << x << endl;
}