#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Универсальная хэш-функция
int hash_f(string data)
{
    const int p = 31; // Простое число p
    const int m = 1e9 + 9; // Большое простое число m
    const int a = 1e9 + 7; // Случайное число a (взято для примера)

    int hash_value = 0;

    for (int i = 0; i < data.size(); ++i)
    {
        hash_value = (1LL * hash_value * p + (data[i] - 'a' + 1)) % m;
    }

    hash_value = (1LL * hash_value * a) % m; // Применяем случайное число a

    return hash_value;
}

struct Hash_table
{
public:
    int size = 10;
    int count{};
    string* data = new string[size];



    Hash_table(int size) :size(size)
    {
        data = new string[size];
        newMem(size);
    }
    Hash_table() {}

    friend int hash_f(string);

    int collizion(int index, int size)
    {
        index = rand() % size;
        if (data[index] != "") { collizion(index, size); }
        else return index;
    }

    void Add(string& value)
    {
        int index = hash_f(value);
        //cout << "Зашифрованная строка:" << '\t' << index << endl;
        if (count == size / 2) { cout << "Увеличиваем размер таблицы в два раза! " << endl; newMem(size * 2); }
        if (data[index % size] != "")
        {
            cout << "Коллизия" << endl;
            index = collizion(index, size);
        }
        else index = index % size;
        data[index] = value;
        ++count;
    }


    void Output()
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            /*
            if (data[i] != "")
            {
            */
                cout << "\nКлюч:\t" << i << '\t';
                cout << "значение:\t" << data[i] << endl;
            //}
        }
    }

    void Search(int key)
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] != "")
            {
                if (i == key)
                {
                    cout << "Ключ:\t" << i << '\t';
                    cout << "значение:\t" << data[i] << endl;
                    return;
                }
            }

        }
        cout << "Элемент не найден" << endl;

    }

    void Remove(int key)
    {
        if (count == 0) { cout << "Таблица пуста! " << endl; return; }
        for (int i = 0; i < size; ++i)
        {
            if (data[i] != "")
            {
                if (i == key)
                {
                    data[i] = "";
                    --count;
                    cout << "Элемент удален" << endl;
                    return;
                }
            }
        }
        cout << "Элемент не найден" << endl;
    }

private:
    void newMem(int newSize)
    {
        string* tmp = data;
        data = new string[newSize];
        for (size_t i = 0; i < size; ++i)
        {
            if (tmp[i] != "")
                data[i] = tmp[i];
            else data[i] = "";

        }
        size = newSize;
        delete[] tmp;
    }

};

void main()
{
    system("chcp 1251");
    clock_t start, end;
    double searching_time;
    int choice = 0;
    int amount = 0;
    string value;
    int key = 0;
    Hash_table* hash1 = new Hash_table();
    for (;;)
    {
        cout << "1 - создание хэш-таблицы\n";
        cout << "2 - добавление элемента\n";
        cout << "3 - вывод\n";
        cout << "4 - Поиск\n";
        cout << "5 - Удаление элемента\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            cout << "Введите размер хэш-таблицы: " << endl;
            cin >> amount;
            hash1 = new Hash_table(amount);
            break;
        case 2:
            cout << "\nВведите строку: ";
            cin.ignore();
            getline(cin, value);
            hash1->Add(value);
            break;
        case 3:
            cout << "\nВывод:\n ";
            hash1->Output();
            break;
        case 4:
            cout << "\nВведите ключ: ";
            cin >> key;
            start = clock();
            hash1->Search(key);
            end = clock();
            searching_time = (double)(end - start) / CLOCKS_PER_SEC;
            cout << "время поиска: " << searching_time << endl;
            break;

        case 5:
            cout << "\nВведите ключ: ";
            cin >> key;
            hash1->Remove(key);
            break;
        case 8:  exit(0);
        }
    }
}