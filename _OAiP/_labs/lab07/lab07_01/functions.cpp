#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "Input the elements into the stask (type 'q' to finish input): " << endl;
	while (cin >> chislo && *chislo != 'q') {
		Stack* data = new Stack;
		data->date = atof(chislo);
		data->next = MyStack->head;
		MyStack->head = data;
	}
	cout << "The data is pushed!\n";
	return;
}

float pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "The stack is empty" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		float a = myStk->head->date;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}





void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "The stack is alreatdy empty!\n"; }
	else {
		while (MyStack->head) {
			Stack* delStack = MyStack->head;
			MyStack->head = MyStack->head->next;
			delete delStack;
		}
	}
}


void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (!MyStack->head) { cout << "The stack is empty:\n"; }
	else { cout << "Here is your stack: \n"; }
	while (data) {
		cout << data->date << "\n";
		data = data->next;
	}
}


void WriteInFile(Stack* myStk) {
	ofstream file1("data.txt");
	Stack* e = myStk->head;
	while (e)
	{
		float data = e->date;
		if (data != 0)
		{
			file1 << data << endl;
			e = e->next;
		}
	}
	file1.close();
	cout << "The stack has been written into the file data.txt\n";
}

void ReadFromFile(Stack* MySt, string fileName) {
	clearStack(MySt);
	float indicate;
	ifstream FILE;
	FILE.open(fileName, ofstream::app);
	if (!(FILE >> indicate)) { cout << "The file is empty\n"; }
	else {
		while (indicate) {
			Stack* data = new Stack;
			data->date = indicate;
			data->next = MySt->head;
			MySt->head = data;
			if (!(FILE >> indicate)) { break; }
		}
		cout << "Data had been read from the file\n";
	}
	FILE.close();
}

void RemoveNode(Stack* previous)
{
	Stack* to_del = previous->next;
	if (!to_del) return; // Если следующего элемента нет, то уходим
	previous->next = to_del->next; // вынимаем из списка
	delete to_del; // чистим память
}


void search(Stack* MySt) {
	int counter = 0;
	Stack* tmp = MySt->head;
	// Удаление головы
	if (MySt->head->date > 100)
	{
		MySt->head = MySt->head->next;
		delete tmp;
		counter++;
		return;
	}

	// Итерируем по списку
	while (tmp->next)
	{
		// если нашли отрицательный элемент
		if (tmp->next->date > 100)
		{
			RemoveNode(tmp);
			counter++;
			return;
		}
		tmp = tmp->next;
	}
	if (counter == 0)
	{
		cout << "Отрицательные элементы отсутсвуют! " << endl;
	}
}