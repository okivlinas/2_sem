#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <windows.h>
#include <algorithm>
typedef struct TNode {
    unsigned int key;
    unsigned int value;
} TNode;
void RSort_step(TNode* source, TNode* dest, unsigned int n, unsigned int* offset, unsigned char sortable_bit)
{
    unsigned char* b = (unsigned char*)&source[n].key + sortable_bit;
    TNode* v = &source[n];
    while (v >= source)
    {
        dest[--offset[*b]] = *v--;
        b -= sizeof(TNode);
    }
}
void RSort_Node(TNode* m, unsigned int n)
{
    // Выделяем память под временный массив
    TNode* m_temp = (TNode*)malloc(sizeof(TNode) * n);
    // Заводим массив корзин
    unsigned int s[sizeof(m->key) * 256] = { 0 };
    // Заполняем массив корзин для всех разрядов
    unsigned char* b = (unsigned char*)&m[n - 1].key;
    while (b >= (unsigned char*)&m[0].key)
    {
        for (unsigned int digit = 0; digit < sizeof(m->key); digit++)
        {
            s[*(b + digit) + 256 * digit]++;
        }
        b -= sizeof(TNode);
    }

    // Пересчитываем смещения для корзин
    for (unsigned int i = 1; i < 256; i++)
    {
        for (unsigned int digit = 0; digit < sizeof(m->key); digit++)
        {
            s[i + 256 * digit] += s[i - 1 + 256 * digit];
        }
    }

    // Вызов сортировки по битам от младших к старшим (LSD)
    for (unsigned int digit = 0; digit < sizeof(m->key); digit++)
    {
        RSort_step(m, m_temp, n - 1, &s[256 * digit], digit);
        TNode* temp = m;
        m = m_temp;
        m_temp = temp;
    }

    // Если ключ структуры однобайтовый, копируем отсортированное в исходный массив
    if (sizeof(m->key) == 1)
    {
        TNode* temp = m;
        m = m_temp;
        m_temp = temp;
        memcpy(m, m_temp, n * sizeof(TNode));
    }

    free(m_temp);
}
//=============================================================
int main()
{
    unsigned int n = 10000000;

    LARGE_INTEGER frequency;
    LARGE_INTEGER t1, t2, t3, t4;
    double elapsedTime;

    TNode* m1 = (TNode*)malloc(sizeof(TNode) * n);
    TNode* m2 = (TNode*)malloc(sizeof(TNode) * n);
    srand(time(NULL));

    for (unsigned int i = 0; i < n; i++)
    {
        m1[i].key = rand() * RAND_MAX + rand();
        m2[i].key = m1[i].key;
    }

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t1);

    RSort_Node(m1, n);

    QueryPerformanceCounter(&t2);
    elapsedTime = (float)(t2.QuadPart - t1.QuadPart) / frequency.QuadPart;
    printf("The RSort:          %.5f seconds\n", elapsedTime);

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t3);

    std::sort(m2, m2 + n, [](const TNode& a, const TNode& b) {return a.key < b.key; });

    QueryPerformanceCounter(&t4);
    elapsedTime = (float)(t4.QuadPart - t3.QuadPart) / frequency.QuadPart;
    printf("The std::sort:      %.5f seconds\n", elapsedTime);

    for (unsigned int i = 0; i < n; i++)
    {
        if (m1[i].key != m2[i].key)
        {
            printf("\n\n!!!!!\n");
            break;
        }
    }

    free(m1);
    free(m2);
    return 0;
}