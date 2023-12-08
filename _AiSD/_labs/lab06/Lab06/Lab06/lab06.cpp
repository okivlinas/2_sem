#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

struct AAA
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = NULL;
	}
};
//-------------------------------
int hf(void* d)                                                                        
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas;
}
//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{                                                         
	srand(time(0));
	int current_size = 0;                                                                                                                  
	cout << "Enter hash-table size: ";                            
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	vector<int> keys;
	clock_t start, end;
	double searching_time;
	int choice;
	int k;
	for (;;)																	
	{
		cout << "\n1 - display hash-table" << endl;
		cout << "2 - add new element" << endl;
		cout << "3 - delete element" << endl;
		cout << "4 - search element" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choise?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;             
			char* str = new char[100];
			bool is_correct = false;
			do {
				cout << "Input phone number: ";
				cin >> k;
				k = k;
				a->key = k;
				if (std::count(keys.begin(), keys.end(), k) == 0 and k > -1) {
					keys.push_back(k);
					is_correct = true;
				}
				else cout << "Incorrect input" << endl;
			} while (!is_correct);
			cout << "Input FIO: ";
			cin.ignore();
			cin.getline(str, 100);
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "Input phone number to delete: ";
			cin >> k;
			b->key = k;
			keys.erase(std::find(keys.begin(), keys.end(), k));
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "Input phone number to search: ";
			cin >> k;
			c->key = k;
			start = clock();
			if (H.search(c) == NULL)
				cout << "element wasn't founded" << endl;
			else
			{
				cout << "element with this phone number: ";
				AAA_print(H.search(c));
				cout << endl;
			}
			end = clock();
			searching_time = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "Searching time: " << searching_time << endl;
		}
			  break;
		}
	}
	return 0;
}