﻿#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct list
{
	int number;
	list* next;
};

void insert(list*&, int);
int del(list*&, int);
int IsEmpty(list*);
void printList(list*);
void menu(void);
void sum5(list*);
void toFile(list*& p);
void fromFile(list*& p);
void find(list*);

void clean(list** h) {
	list* p, * p1;
	p = *h;
	while (p != NULL) {
		p1 = p->next;
		delete p;
		p = p1;
	}
	*h = NULL;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	int value;
	menu();
	cout << " Что дальше? ";
	cin >> choice;
	while (choice != 8)
	{
		switch (choice)
		{
		case 1: cout << "Введите число ";
			cin >> value;
			insert(first, value);
			break;
		case 2:
			printList(first);
			break;
		case 3: if (!IsEmpty(first))
		{
			cout << "Введите удаляемое число ";
			cin >> value;
			if (del(first, value))
			{
				cout << "Удалено число " << value << endl;
				printList(first);
			}
			else
				cout << "Число не найдено" << endl;
		}
			  else
			cout << "Список пуст" << endl;
			break;
		case 4: sum5(first);
			break;
		case 5: toFile(first);
			break;
		case 6:
			clean(&first);
			fromFile(first);
			break;
		case 7: find(first);
			break;
		default: cout << "Неправильный выбор" << endl;
			menu();
			break;
		}
		cout << "Что дальше? ";
		cin >> choice;
	}
	cout << "Конец" << endl;
	return 0;
}

void menu(void)
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Вывод числа" << endl;
	cout << " 3 - Удаление числа" << endl;
	cout << " 4 - Вычисление суммы положительных чисел" << endl;
	cout << " 5 - Запись в файл" << endl;
	cout << " 6 - Вывод из файла" << endl;
	cout << " 7 - Поиск элемента" << endl;
	cout << " 8 - Конец" << endl;
}

void insert(list*& p, int value)
{
	list* newP = new list;
	if (newP != NULL)
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

int del(list*& p, int value)
{
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}

int IsEmpty(list* p)
{
	return p == NULL;
}

void printList(list* p)
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void sum5(list* p)
{
	int sm = 0, l = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{

			if (p->number < 0 && p->number % 2 == 0)

				sm = sm + (p->number);
			p = p->next;


		}
		if (sm)cout << "Сумма = " << sm << endl;
		else cout << "Таких элементов нет" << endl;
	}

}
void toFile(list*& p)
{
	list* temp = p;
	ofstream file1("mList.txt");
	if (file1.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		int nn = temp->number;
		file1 << nn << "\n";
		temp = temp->next;
	}
	file1.close();
	cout << "Список записан в файл\n";
}
void fromFile(list*& p)
{
	char buf[10];
	int a[1001], ans = 0;
	ifstream file1("mList.txt");
	if (file1.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (!file1.eof())
	{
		file1.getline(buf, 10);
		a[ans] = atoi(buf);
		ans++;
	}
	file1.close();
	for (int i = ans - 2; i > -1; i--)
	{
		insert(p, a[i]);
	}
}
void find(list* p)
{
	bool isFnd = false;
	int element, ans=0;
	cout << "Введите элемент:" << endl;
	cin >> element;
	list* fnd = p;
	while (fnd)
	{
		ans++;
		if (fnd->number == element)
		{
			isFnd = true;
			printf("Элемент найден. Позиция ans\n");
			break;
		}
		fnd = fnd->next;
	}
	if (!isFnd)
		printf("Элемент не найден\n");

}