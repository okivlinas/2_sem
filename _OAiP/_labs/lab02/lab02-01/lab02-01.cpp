#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    int i = 0, a1[101], a2[101], a3[101], o = 0, n = 8, mx, tmp;

    FILE* k1;
    FILE* k2;
    FILE* k3;

    fopen_s(&k1, "NameA.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf_s(k1, "%d", &a1[i]);
    }
    fopen_s(&k2, "NameB.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf_s(k2, "%d", &a2[i]);
    }
    fopen_s(&k3, "NameC.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf_s(k3, "%d", &a3[i]);
    }

    fclose(k1);
    fclose(k2);
    fclose(k3);

    FILE* k4;
    fopen_s(&k4, "NameD.txt", "a");
    for (int i = 0; i < n-1; i++) {
        tmp = max(a1[i], a2[i]);
        mx = max(tmp, a3[i]);
        fprintf_s(k4, "%d", mx);
        fprintf_s(k4, "%c", ',');
    }
    tmp = max(a1[n-1], a2[n-1]);
    mx = max(tmp, a3[n-1]);
    fprintf_s(k4, "%d", mx);
    fclose(k4);
}