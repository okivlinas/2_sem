#include <iostream>
#include <fstream>
#include <string>

# define str_len 256
# define size 100

using namespace std;

void enter_new();
void out();
void del();
void search();

struct sklad
{
	string name_of_product;
	double cell;
	int many;
	int per;
};
enum percent
{
	five = 5, seven = 7, eleven = 11, twenty = 20, twentyfive = 25, thirty = 30
};

sklad productonsclad[size];
sklad all;

int choice, current_size = 0;
double sell;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	cout << "введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для удаления" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: del(); break;
		case 4: search(); break;
		}
	} while (choice != 5);
}
void enter_new()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "ввод информации" << endl;
	if (current_size < size)
	{
		cout << "строка номер ";
		cout << current_size + 1;
		cout << endl << "наименование товара" << endl;
		cin.get();
		getline(cin, productonsclad[current_size].name_of_product);
		cout << "цена" << endl;
		cin >> productonsclad[current_size].cell;
		cout << "количество" << endl;
		cin >> productonsclad[current_size].many;
		cout << "процентная надбавка(5, 7, 11, 20, 25, 30)" << endl;
		cin >> productonsclad[current_size].per;
		current_size++;
	}
	else cout << "введено максимальное кол-во строк";
	cout << "что дальше?" << endl;
	cin >> choice;
}

void out()
{
	setlocale(LC_CTYPE, "Russian");
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "строка номер "; cin >> n;
		cout << endl << "наименование товара:" << endl;
		cout << productonsclad[n - 1].name_of_product << endl;
		cout << "цена:" << endl;
		cout << productonsclad[n - 1].cell << endl;
		cout << "количество:" << endl;
		cout << productonsclad[n - 1].many << endl;
		if (productonsclad[n - 1].per == 5)
		{
			cout << "процентная надбавка=" << five << "%" << endl;
		}
		else if (productonsclad[n - 1].per == 7)
		{
			cout << "процентная надбавка=" << seven << "%" << endl;
		}
		else if (productonsclad[n - 1].per == 11)
		{
			cout << "процентная надбавка=" << eleven << "%" << endl;
		}
		else if (productonsclad[n - 1].per == 20)
		{
			cout << "процентная надбавка=" << twenty << "%" << endl;
		}
		else if (productonsclad[n - 1].per == 25)
		{
			cout << "процентная надбавка=" << twentyfive << "%" << endl;
		}
		else if (productonsclad[n - 1].per == 30)
		{
			cout << "процентная надбавка=" << thirty << "%" << endl;
		}

	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "наименование товара:" << endl;
			cout << productonsclad[i].name_of_product << endl;
			cout << "цена:" << endl;
			cout << productonsclad[i].cell << endl;
			cout << "количество:" << endl;
			cout << productonsclad[i].many << endl;
			if (productonsclad[i].per == 5)
			{
				cout << "процентная надбавка=" << five << "%" << endl;
			}
			else if (productonsclad[i].per == 7)
			{
				cout << "процентная надбавка=" << seven << "%" << endl;
			}
			else if (productonsclad[i].per == 11)
			{
				cout << "процентная надбавка=" << eleven << "%" << endl;
			}
			else if (productonsclad[i].per == 20)
			{
				cout << "процентная надбавка=" << twenty << "%" << endl;
			}
			else if (productonsclad[i].per == 25)
			{
				cout << "процентная надбавка=" << twentyfive << "%" << endl;
			}
			else if (productonsclad[i].per == 30)
			{
				cout << "процентная надбавка=" << thirty << "%" << endl;
			}

		}

	}
	cout << "что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nномер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			productonsclad[de1] = productonsclad[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			productonsclad[i] = all;
	cout << "что дальше?" << endl;
	cin >> choice;
}
void search()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "цена товара:" << "\n";
	cin >> sell;
	for (int z = 0; z < current_size; z++)
	{
		if (sell == productonsclad[z].cell)
		{
			cout << endl << "наименование товара:" << endl;
			cout << productonsclad[z].name_of_product << endl;
			cout << "цена:" << endl;
			cout << productonsclad[z].cell << endl;
			cout << "количество:" << endl;
			cout << productonsclad[z].many << endl;
			if (productonsclad[z].per == 5)
			{
				cout << "процентная надбавка=" << five << "%" << endl;
			}
			else if (productonsclad[z].per == 7)
			{
				cout << "процентная надбавка=" << seven << "%" << endl;
			}
			else if (productonsclad[z].per == 11)
			{
				cout << "процентная надбавка=" << eleven << "%" << endl;
			}
			else if (productonsclad[z].per == 20)
			{
				cout << "процентная надбавка=" << twenty << "%" << endl;
			}
			else if (productonsclad[z].per == 25)
			{
				cout << "процентная надбавка=" << twentyfive << "%" << endl;
			}
			else if (productonsclad[z].per == 30)
			{
				cout << "процентная надбавка=" << thirty << "%" << endl;
			}

		}

	}
	cout << "что дальше?" << endl;
	cin >> choice;
}