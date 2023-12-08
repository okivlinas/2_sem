#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;

double radians(double degrees) {
    return degrees * pi / 180.0;
}

double sin_sum(int n, double degrees) {
    double x = radians(degrees);
    if (n == 1) {
        return sin(x);
    }
    else {
        return sin(n * x) + sin_sum(n - 1, degrees);
    }
}

int main() {

    setlocale(LC_CTYPE, "Russian");

    int n;
    double degrees;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите угол x в градусах: ";
    cin >> degrees;
    double result = sin_sum(n, degrees);
    cout << "Результат: " << result << endl;
    return 0;
}