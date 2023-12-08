#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    ifstream fin;   
    fin.open("FILE1.txt");
    ofstream fout;
    fout.open("FILE2.txt");
    if (!fin.is_open())cout << "Файл не может быть открыт" << endl;
    else {
        while (!fin.eof()) {
            int num = 0, index = 0, fl = 0, arr[3], j = 0;
            string temp;

            getline(fin, temp);
            for (string::size_type i = 0; i < temp.size(); i++)
            {
                if (temp[i] == ' ')fl++;
            }
            if (fl == 0) {
                fout << temp << endl;
            }
        }
        fin.close();
    }

    ifstream finn;
    finn.open("FILE2.txt");
    if (!finn.is_open())cout << "Файл не может быть открыт" << endl;
    else {
        while (!finn.eof()) {
            int num = 0, index = 0, fl = 0, arr[3], j = 0, ans = 0;
            string temp;

            getline(finn, temp);
            if (temp.size() == 5) {
                cout << temp << endl;
            }
        }
        finn.close();
    }
}