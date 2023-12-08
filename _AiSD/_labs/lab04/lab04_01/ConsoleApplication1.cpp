#include <iostream>

using namespace std;

int task1(int n) {

	int a[101], b[101], ans = 0;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		a[i] = 1 + rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[i])swap(a[i], a[j]);
		}
	}
	for (int i = 0, j = 0; i < (n + 1) / 2; i++, j += 2) {
		b[j] = a[i];
		ans += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])swap(a[i], a[j]);
		}
	}
	for (int i = 0, j = 1; i < n / 2; i++, j += 2) {
		b[j] = a[i];
	}
	cout << "Один из возможных вариантов вывода: ";
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl << "Максимальная сумма чека: " << ans << endl;
	return 0;
}
int task2(int n) {

	int a[101], ans = 1, ans_t = 0;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		a[i] = 1 + rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;

	if (n <= 3) {
		cout << "Количество призёров: " << n << endl;
		return 0;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i; j < n; j++) {
				if (a[j] > a[i])swap(a[i], a[j]);
			}
		}
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1])ans_t++;
			if (ans_t == 3)break;
			else ans++;
		}
		cout << "Количество призёров: " << ans << endl;
		return 0;
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int n = 0;
	cout << "Задача 1" << endl << "n: ";
	cin >> n;
	task1(n);
	cout << "Задача 2" << endl << "n: ";
	cin >> n;
	task2(n);
}