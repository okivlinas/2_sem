#include <iostream>
#include <iomanip>
#include <time.h> 

using namespace std;

int n, i, j, m, l, a[10001], sw, ss;

int fib(int);

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    cout << "1 - цикл, 2 - рекурсия" << endl;
    cin >> ss;
    if (ss == 1) {
        double seconds = 0.0
        clock_t start = clock();
        a[0] = 0, a[1] = 1;
        cin >> n;
        for (i = 2; i < n; i++) {
            a[i] = a[i - 2] + a[i - 1];
        }
        cout << "Число с номером n: " << a[n - 1] << endl; 
        clock_t end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        cout << fixed << setprecision(6);
        if (seconds > 60) {
            l = seconds / 60;
            sw = seconds - l * 60;
        }
        else {
            l = 0;
            sw = seconds;
        }
        cout << "Расчетное время циклом: " << l << " минут " << sw << " секунд" << endl;
    }
    else {
        clock_t start = clock();
        cin >> n;
        for (i = 0; i < n; i++)
        {
            m = fib(i);
        }
        cout << "Число с номером n: " << m << endl;
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        cout << fixed << setprecision(6);
        if (seconds > 60) {
            l = seconds / 60;
            sw = seconds - l * 60;
        }
        else {
            l = 0;
            sw = seconds;
        }
        cout << "Расчетное время рекурсией: " << l << " минут " << sw << " секунд" << endl;
    }
    return 0;
}
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}