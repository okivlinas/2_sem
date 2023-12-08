#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read(string str) {
    ofstream fout;
    fout.open("FILE1.txt");
    fout << str;
}

int write(int k) {
    string tmp;
    int ans = 0;
    ifstream fin;
    fin.open("FILE1.txt");
    if (!fin.is_open())cout << "Файл не может быть открыт" << endl;
    else {
        while (!fin.eof()) {
            getline(fin, tmp);
            for (int i = 1; i <= k; i++) {
                if (tmp[i] == ' ' && tmp[i-1]>'9')ans++;
            }
            if (tmp[k] != ' ' && tmp[k - 1] > '9')ans++;
        }
        fin.close();
        return ans;
    }
    return 0;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    string str;
    int k;

    getline(cin, str);
    cout << "k: ";
    cin >> k;
    read(str);
    cout << write(k) << endl;
}