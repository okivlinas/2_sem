#include <iostream>

using namespace std;

long long pluss(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return pluss(a + 1, b - 1);
    }
}

long long minuss(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    else {
        return minuss(a - 1, b - 1);
    }
}

long long multi(long long a, long long b) {
    if (b == 0) {
        return 0;
    }
    else if (b == 1) {
        return a;
    }
    else {
        return pluss(multi(a, b - 1), a);
    }
}

long long power(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    else {
        return multi(a, power(a, b - 1));
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    long long n, m;

    cout << "Введите значения n и m: ";
    cin >> n >> m;

    cout << "Сумма: " << pluss(n, m) << endl;
    cout << "Разность: " << minuss(n, m) << endl;
    cout << "Умножение: " << multi(n, m) << endl;
    cout << "Возведение в степень: " << power(n, m) << endl;

    return 0;
}
