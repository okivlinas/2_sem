#include <iostream>

using namespace std;

long long n, am, ab, a[10001], x, lg, ans;

int main() {

    setlocale(LC_ALL, "rus");
    cout << "Введите N: ";
    cin >> n;

    am = 1;
    ab = n;
    lg = ceil(log2(n));

    for (int i = 0; i < lg; i++) {
        x = (am + ab) / 2;
        a[i] = x;
        cout << "Искомое число " << x << "?" << endl;
        cout << "1 - меньше; 2 - больше; 3 - верно." << endl;
        cin >> ans;
        if (ans == 1) {
            ab = x - 1;
        }
        if (ans == 2) {
            am = x + 1;
        }
        if (ans == 3) {
            cout << "Максимальное число шагов = " << lg << endl;
            for (int j = 0; j <= i; j++) {
                cout << a[j] << endl;
            }
            return 0;
        }
    }
}