#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const unsigned int NAME_SIZE = 50;
const unsigned int CITY_SIZE = 40;
int am_st;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

void insert(Address* e, Address** phead, Address** plast) //add an element to end of list
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

void insert(Address adr[10]) {
	cout << "Input the name: ";
	cin.get();
	cin.getline(adr[am_st].name, NAME_SIZE);
	cout << "\nInput the city: ";
	cin.getline(adr[am_st].city, CITY_SIZE);
	am_st++;
}

void addToHead(Address* e, Address** phead, Address** plast)
{
	Address* p = *phead;
	if (*phead == NULL) {
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else {
		p->prev = e;
		e->next = p;
		e->prev = NULL;
		*phead = e;
	}
}

Address* setElement1() // Создание элемента и ввод его значений с клавиатуры
{
	ifstream file2("Lip.txt");

	Address* temp = new Address();
	if (!temp)
	{
		cerr << "Error giving the memory";
		return NULL;
	}
	file2.getline(temp->name, NAME_SIZE);
	file2.getline(temp->city, CITY_SIZE);
	temp->next = NULL;
	temp->prev = NULL;
	file2.close();
	return temp;

}

void fromFile(Address adr[10])
{
	int counter = 0;
	char temp[100];
	int i = 0;
	char buf[256];
	ifstream file5("Lip.txt");
	while (file5) {
		file5.getline(temp, 20);
		counter++;
	}
	file5.close();
	ifstream file2("Lip.txt");
	if (file2.fail())
	{
		cout << "\nError opening the file";
		exit(1);
	}
	for (int j = 0; j < counter / 2; j++)
	{
		file2.getline(adr[i].name, NAME_SIZE);
		cout << adr[i].name << endl;
		file2.getline(adr[i].city, CITY_SIZE);
		cout << adr[i].city << endl;
		i++;
		am_st++;
	}
	file2.close();
}

Address* setElement() // Создание элемента и ввод его значений с клавиатуры
{
	Address* temp = new Address();
	if (!temp)
	{
		cerr << "Error giving the memory";
		return NULL;
	}
	cout << "Input the name: ";
	cin.get();
	cin.getline(temp->name, NAME_SIZE);
	cout << "Input the sity: ";
	cin.getline(temp->city, CITY_SIZE);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address adr[10]) {
	for (int i = 0; i < am_st; i++) {
		cout << adr[i].name << endl;
		cout << adr[i].city << endl;
	}
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast) //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << '\n' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead) // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "The name isn't founded" << endl;
	else
		cout << t->name << '\n' << t->city << endl;
}

void find(Address adr[10], string name1) {
	for (int i = 0; i < am_st; i++) {
		if (adr[i].name == name1) {
			cout << adr[i].name << endl;
			cout << adr[i].city << endl;
		}
	}
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)// Удаление элемента по имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "The name isn't founded" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Elemnet had been deleted" << endl;
	}
}

void delet(Address adr[10], string name1) {
	for (int i = 0; i < am_st; i++) {
		if (adr[i].name == name1) {
			for (int j = i; j < am_st; j++) {
				adr[j] = adr[j + 1];
			}
			am_st--;
		}
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead) //Запись в файл
{
	struct Address* t = *phead;
	ofstream file1("Lip.txt");
	if (file1.fail())
	{
		cerr << "Fail cannot be opened" << endl;
		exit(1);
	}
	cout << "Saved into the file" << endl;
	while (t)
	{
		file1 << t->name << "\n" << t->city << endl;
		t = t->next;
	}
	file1.close();
}

Address* findMax(Address* phead, string field) {
	Address* max = phead;
	Address* cur = phead;
	while (cur != NULL) {
		if (field == "name" && strcmp(cur->name, max->name) > 0) {
			max = cur;
		}
		else if (field == "city" && strcmp(cur->city, max->city) > 0) {
			max = cur;
		}
		cur = cur->next;
	}
	return max;
}


int main()
{
	Address* head = NULL;
	Address* last = NULL;

	Address adr[10];

	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1 - add new element" << endl;
	cout << "2 - delete the element" << endl;
	cout << "3 - display elements" << endl;
	cout << "4 - search" << endl;
	cout << "5 - write into the file" << endl;
	cout << "6 - read from the file" << endl;
	cout << "7 - find max element" << endl;
	cout << "8. exit" << endl;
	cout << endl;
	bool falg = false;
	for (;;)
	{
		cout << "Your choise: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			if (falg == false)
				insert(setElement(), &head, &last);
			else
				insert(adr);
		}
			  break;
		case 2: { char dname[NAME_SIZE];
			if (falg == false) {
				cout << "Input the name: ";
				cin >> dname;
				delet(dname, &head, &last);
			}
			else {
				string nm;
				cout << "Input the name: ";
				cin.get();
				getline(cin, nm);
				delet(adr, nm);
			}
		}
			  break;
		case 3: if (falg == false) {
			outputList(&head, &last);
		}
			  else {
			outputList(adr);
		}
			  break;
		case 4: { char fname[NAME_SIZE];
			string fn;
			if (falg == false) {
				cout << "Input the name: ";
				cin.get();
				cin.getline(fname, NAME_SIZE);
				find(fname, &head);
			}
			else {
				cout << "Input the name: ";
				cin.get();
				getline(cin, fn);
				find(adr, fn);
			}
		}
			  break;
		case 5: {
			writeToFile(&head);
		}
			  break;
		case 6: {
			fromFile(adr);
			falg = true;
		}
			  break;
		case 7: {
			string field;
			cout << "Enter the field to find max (name or city): ";
			cin >> field;
			Address* max = findMax(head, field);
			cout << "Max element:" << endl;
			cout << max->name << '\n' << max->city << endl;
		}
			  break;
		case 8: exit(0);
		default: exit(1);
		}
	}
	return 0;
}