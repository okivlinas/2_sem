#include <string>
#include <iostream>
#include <fstream>

#define size 100

using namespace std;

void enter_new();
void out();
void search();
void ofile();
void ifile();

union forSklad
{
	char str[50];
	int limb;
	double dbl;
};
struct Sklad
{
	forSklad name_of_product;
	forSklad cell;
	forSklad many;
	forSklad per;
};
Sklad productOnSclad[size];

int current_size = 0, choice;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для вывода в файл" << endl;
	cout << "5-для вывода из файла" << endl;
	cout << "6-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
			case 1: enter_new(); break;
			case 2: out(); break;
			case 3: search(); break;
			case 4: ofile(); break;
			case 5: ifile(); break;
		}
	} 
	while (choice != 6);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименование товара" << endl;
		cin.get();
		cin.get(productOnSclad[current_size].name_of_product.str,40);
		cout << "Цена" << endl;
		cin >> productOnSclad[current_size].cell.dbl;
		cout << "Количество" << endl;
		cin >> productOnSclad[current_size].many.limb;
		cout << "Процентная надбавка" << endl;
		cin >> productOnSclad[current_size].per.limb;
		current_size++;

	}
	else cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		cout << endl << "Наименование товара:" << endl;
		cout << productOnSclad[n - 1].name_of_product.str << endl;
		cout << "Цена:" << endl;
		cout << productOnSclad[n - 1].cell.dbl << endl;
		cout << "Количество:" << endl;
		cout << productOnSclad[n - 1].many.limb << endl;
		cout << "Процентная надбавка:" << endl;
		cout << productOnSclad[n - 1].per.limb << "%" << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Наименование товара:" << endl;
			cout << productOnSclad[i].name_of_product.str << endl;
			cout << "Цена:" << endl;
			cout << productOnSclad[i].cell.dbl << endl;
			cout << "Количество:" << endl;
			cout << productOnSclad[i].many.limb << endl;
			cout << "Процентная надбавка:" << endl;
			cout << productOnSclad[i].per.limb << "%" << endl;

		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void ofile()
{
	int N = 10;
	string buf;
	int num;
	do {
		cout << "Введите количество: ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tТовар №" << i + 1 << '\n';
		file1 << "\tТовар №" << i + 1 << '\n';
		cout << "Введите наименование товара:\n";
		file1 << "наименование товара: ";
		cin >> productOnSclad[current_size].name_of_product.str;
		file1 << productOnSclad[current_size].name_of_product.str;
		cout << "цена:\n";
		file1 << "\nцена: ";
		cin >> productOnSclad[current_size].cell.dbl;
		file1 << productOnSclad[current_size].cell.dbl << "\n";
		cout << "количество:\n";
		file1 << "количество: ";
		cin >> productOnSclad[current_size].many.limb;
		file1 << productOnSclad[current_size].many.limb << "\n";
		cout << "процентная надбавка:\n";
		file1 << "процентная надбавка: ";
		cin >> productOnSclad[current_size].per.limb;
		file1 << productOnSclad[current_size].per.limb << "\n\n";
	}
	cout << "\n\n";
}
void ifile()
{
	int h = 0;
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
		h++;
		if (h == 5) {
			exit(0);
		}
	}
}
void search()
{
	char name[50];
	cout << "Введите наименование товара:" << "\n";
	cin.get();
	cin.get(name, 40);
	for (int z = 0; z < current_size; z++)
	{ 
		if (strcmp(name, productOnSclad[z].name_of_product.str) == 0)
		{
			cout << endl << "Наименование товара:" << endl;
			cout << productOnSclad[z].name_of_product.str << endl;
			cout << "Цена:" << endl;
			cout << productOnSclad[z].cell.dbl << endl;
			cout << "Количество:" << endl;
			cout << productOnSclad[z].many.limb << endl;
			cout << "Процентная надбавка:" << endl;
			cout << productOnSclad[z].per.limb << "%" << endl;

		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}