#include <iostream>
#include <fstream>
#include <string>

#define size 30

using namespace std;

struct aviasales
{
	int number;
	char dest[30];
	char time[6];
	char date[11];
	double cost;
	int col_pl;
};
struct aviasales avialist[size];
struct aviasales bad;

int ch, num;

void ent_new() //функция ввода
{
	cout << "Ввод новой записи" << endl;
	if (num < size)
	{
		cout << "Строка номер: " << num + 1 << endl;

		cout << "Номер рейса: ";
		cin >> avialist[num].number;
		getchar();
		cout << "Пункт назначения: ";
		gets_s(avialist[num].dest);

		cout << "Время вылета: ";
		gets_s(avialist[num].time);

		cout << "Дата вылета: ";
		gets_s(avialist[num].date);

		cout << "Стоимость билета: ";
		cin >> avialist[num].cost;

		cout << "Количество мест: ";
		cin >> avialist[num].col_pl;

		num++;
	}
	else cout << "Введено максимальное кол-во строк";
}
void outputOneStructure(aviasales str) //вывод одной строки
{
	cout << "Номер рейса: ";
	cout << str.number << endl;
	cout << "Пункт назначения: ";
	cout << str.dest << endl;
	cout << "Время вылета: ";
	cout << str.time << endl;
	cout << "Дата вылета: ";
	cout << str.date << endl;
	cout << "Стоимость билета:  ";
	cout << str.cost << endl;
	cout << "Количество мест: ";
	cout << str.col_pl << endl;
	cout << endl;
}
void out() //функция вывода информации
{
	int sw, n;
	cout << "1 - вывод одной строки" << endl;
	cout << "2 - вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;
		cin >> n;
		cout << endl;
		cout << "Срока №" << n << endl;
		outputOneStructure(avialist[n - 1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < num; i++)
		{
			cout << "Строка №" << i + 1 << endl;
			outputOneStructure(avialist[i]);
		}
	}
}
void del() //функция удаления
{
	int d;
	cout << "Номер строки, которую необходимо удалить(для удаления всех строк нажать 666)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int i = (d - 1); i < num; i++)
			avialist[i] = avialist[i + 1];
		num = num - 1;
	}
	if (d == 666)
		for (int i = 0; i < size; i++)
			avialist[i] = bad;

}
void search() //функция поиска информаци
{
	int ans = 0;
	char pol_for_search[size];
	string pol_for_search1;
	cout << "Введите пункт назначения для поиска" << endl;
	getchar();
	gets_s(pol_for_search);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		pol_for_search1 = avialist[i].dest;
		if (pol_for_search == pol_for_search1)
		{
			ans++;
			outputOneStructure(avialist[i]);
		}

	}
	cout << "Всего найдено: " << ans << " пунктов" << endl;
}
void ofile()
{
	int n, buf1;
	string buf2;
	ofstream out;          // поток для записи
	out.open("file.txt");      // открываем файл для записи
	if (out.is_open())
	{
		cout << "Введите количество вводимых строк: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			out << "Запись №" << i + 1 << endl;

			cout << "Введите номер рейса: ";
			cin >> buf1;
			out << "Номер рейса: " << buf1 << endl;

			getchar();
			cout << "Введите пункт назначения: ";
			getline(cin, buf2);
			out << "Пункт назначеня: " << buf2 << endl;

			cout << "Введите время вылета: ";
			getline(cin, buf2);
			out << "Время вылета: " << buf2 << endl;

			cout << "Введите дату вылета: ";
			getline(cin, buf2);
			out << "Дата вылета: " << buf2 << endl;

			cout << "Введите стоимость билета: ";
			cin >> buf1;
			out << "Стоимость билета: " << buf1 << endl;

			cout << "Введите количество мест: ";
			cin >> buf1;
			out << "Количество мест: " << buf1 << endl << endl;
		}
	}
	out.close();
	cout << "File has been written" << endl;
}
void ifile()
{
	string line;

	ifstream in("file.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;	
		}
	}
	in.close();     // закрываем файл
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Данных нет" << endl;
	do
	{
		cout << "Введите:" << endl;
		cout << "1 - ввод новой записи" << endl;
		cout << "2 - вывода записи(-ей)" << endl;
		cout << "3 - удаление записи" << endl;
		cout << "4 - поиск по пункту назначения" << endl;
		cout << "5 - запись в файл" << endl;
		cout << "6 - чтение из файла" << endl;
		cout << "7 - для выхода" << endl;
		cin >> ch;

		switch (ch)
		{
		case 1: ent_new();	break;
		case 2: out();	break;
		case 3: del();	break;
		case 4: search();	break;
		case 5: ofile();	break;
		case 6: ifile();	break;
		}
	} while (ch != 7);
	cout << "Программа завершена!" << endl;
}
/*
//Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж).Реализовать выборку по полу и году рождения.
# include <iostream>
#include <iostream>
#include <fstream>
#include <string>
# define str_len 30
# define size 30
int choice;
using namespace std;
struct Gorozhanin //структура
{
	char name[str_len];
	int year_of_birth;
	char adres[str_len];
	char pol[str_len];
};
struct Gorozhanin list_of_gorozhanin[size];
struct Gorozhanin bad;
int current_size = 0;
void enter_new() //функция ввода
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{

		printf("\n Строка номер %d \n", current_size + 1);

		printf(" ФИО \r\n");
		getchar();
		gets_s(list_of_gorozhanin[current_size].name);

		printf(" Год рождения \n");
		cin >> list_of_gorozhanin[current_size].year_of_birth;


		printf(" Пол(м_ж) \n");
		cin >> list_of_gorozhanin[current_size].pol;

		printf(" Адрес \n");
		getchar();
		gets_s(list_of_gorozhanin[current_size].adres);
		printf("\n ");
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}
void ofile()
{
	int N = 10;
	string buf;
	int num;
	do {
		cout << "Введите количество грожданинов: ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tГрожданин №" << i + 1 << '\n';
		file1 << "\tГрожданин №" << i + 1 << '\n';
		cout << "Введите ФИО клиента:\n";
		file1 << "ФИО клиента: ";
		cin >> list_of_gorozhanin[current_size].name;
		file1 << list_of_gorozhanin[current_size].name ;
		cout << "Введите год рождения:\n";
		file1 << "\nГод: ";
		cin >> list_of_gorozhanin[current_size].year_of_birth;
		file1 << list_of_gorozhanin[current_size].year_of_birth << "\n";
		cout << "Введите пол:\n";
		file1 << "Пол: ";
		cin >> list_of_gorozhanin[current_size].pol;
		file1 << list_of_gorozhanin[current_size].pol << "\n";
		cout << "Введите адрес:\n";
		file1 << "Адрес: ";
		cin >> list_of_gorozhanin[current_size].adres;
		file1 << list_of_gorozhanin[current_size].adres << "\n\n";
	}
	cout << "\n\n";
}
void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}
void del() //функция удаления
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_gorozhanin[de1] = list_of_gorozhanin[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_gorozhanin[i] = bad;

}


void outputOneStructure(Gorozhanin oneGorozhanin) //вывод одной строки
{
	cout << "Фамилия ";
	cout << oneGorozhanin.name << endl;
	cout << "Год рождения ";
	cout << oneGorozhanin.year_of_birth << endl;
	cout << "Адрес  ";
	cout << oneGorozhanin.adres << endl;
	cout << "Пол(м,ж) ";
	cout << oneGorozhanin.pol << endl;
	cout << endl;
}


void out() //функция вывода информации
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		outputOneStructure(list_of_gorozhanin[n - 1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			outputOneStructure(list_of_gorozhanin[i]);
		}
	}
}
void search() //функция поиска информаци
{
	int year_for_search = 0;
	char  pol_for_search[str_len];
	cout << "Введите год рождения для поиска" << endl;;
	cin >> year_for_search;
	cout << endl;;
	int amount = 0;
	bool ignorePol = false;
	if (strcmp(pol_for_search, "*") == 0) {
		ignorePol = true;
	}
	printf("Результат:\n");
	for (int i = 0; i < size; i++)
	{

			if (year_for_search == list_of_gorozhanin[i].year_of_birth)
			{
				amount++;
				outputOneStructure(list_of_gorozhanin[i]);
			}

	}
	printf("Всего найдено:%d\n\n", amount);


}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Данных нет" << endl;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для поиска по году рождения" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для ввода в файл" << endl;
		cout << "6-для вывода из файла" << endl;
		cout << "6-для выхода" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3: search(); break;
		case 4:  out();	break;
		case 5: ofile();	break;
		case 6: ifile();	break;
		}
	} while (choice != 5);
}*/