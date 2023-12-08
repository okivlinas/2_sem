#include "Header.h"
#include <iostream>
using namespace std;
using namespace heap;
heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	Heap* ph2 = &h2;
	for (;;)
	{
		std::system("cls");
		h1.scan(0);
		cout << "1 - добавить элемент" << endl;
		cout << "2 - удалить максимальынй" << endl;
		cout << "3 - удалить минимальный" << endl;
		cout << "4 - удалить i-элемент " << endl;
		cout << "5 - объединение куч" << endl;
		cout << "0 выход." << endl;
		cout << "ваш выбор? ";
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: {	AAA* a = new AAA;
			cout << "введите элемент:" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 2:   h1.extractMax();
			break;
		case 3:   h1.extractMin();
			break;
		case 4:
			int i;
			cout << "введите i:\n";
			cin >> i;
			h1.extractI(i);
			break;
		case 5:
		{
			int j = 1;
			cout << "объединение:\n";
			while (j > 0)
			{
				AAA* b = new AAA;
				cout << "введите эелементы для второй кучи" << endl;
				cout << "конец - отрицательное число" << endl;
				cin >> j;
				if (j > 0)
				{
					b->x = j;
					h2.insert(b);
				}
			}
			h1.unionHeap(ph2);
			break;
		}
		default: break;
		}
		std::system("pause");
	} return 0;
}