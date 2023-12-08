#include <iostream>
#include <iomanip>
#include <time.h> 

using namespace std;

void sort1(int b[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (b[i] < b[j])swap(b[i], b[j]);
        }
    }
    cout << "B(sort): ";
    for (int i = 0; i < n; i++)cout << b[i] << " ";
}
void sort2(int c[], int n) {
    int i = 0, j = 0, t = 0;
    for (int r = n / 2; r > 0; r /= 2)
        for (i = r; i < n; i++)
        {
            t = c[i];
            for (j = i; j >= r; j -= r)
            {
                if (t < c[j - r])
                    c[j] = c[j - r];
                else
                    break;
            }
            c[j] = t;
        }
    cout << "C(sort): ";
    for (i = 0; i < n; i++)cout << c[i] << " ";
}
void sort3(int d[], int n) {
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (d[i] > d[j])swap(d[i], d[j]);
        }
    }
    cout << "D(sort): ";
    for (i = 0; i < n; i++)cout << d[i] << " ";
    double end = clock();
}
int sort4(int* E, int n)
{
    int i = 0;
    int j = n - 1;
    int mid = *(E + n / 2);

    do {

        while (*(E + i) < mid)
            i++;

        while (*(E + j) > mid)
            j--;

        if (i <= j) {
            swap(*(E + i), *(E + j));
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0)
        sort4(E, j + 1);

    if (i < n)
        sort4((E + i), n - i);

    return *E;
}

int main()
{
    cout << fixed << setprecision(5);
    srand(time(0));
    int n = 0, a[10001], b[10001], c[10001], d[10001], e[10001], t, i, j;
    double f;
    cout << "n: ";
    cin >> n;

    cout << "A: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        b[i] = c[i] = d[i] = e[i] = a[i];
    }
    double start1 = clock();
    sort1(b, n);
    double end1 = clock();
    cout << "  time(B): " << fixed << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;

    double start2 = clock();
    sort2(b, n);
    double end2 = clock();
    cout << "  time(C): " << fixed << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

    double start3 = clock();
    sort1(b, n);
    double end3 = clock();
    cout << "  time(D): " << fixed << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

    double start4 = clock();
    sort4(e, n);
    cout << "E(sort): ";
    for (i = 0; i < n; i++)cout << e[i] << " ";
    double end4 = clock();
    cout << "  time(E): " << fixed << (double)(end4 - start4) / CLOCKS_PER_SEC << endl;
}