/*
    Лабораторная работа №1
    Вариант 15: Рассортировать элементы главной диагонали квадратной матрицы порядка n по возрастанию.
    Память под матрицу выделять динамически. Необходимо освобождать память, выделенную под матрицу.
*/

#include <iostream>
#include <time.h>
#include <cstdlib> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int n; 
    cout << "Введите размерность матрицы:";
    cin >> n;
    while (n < 2)
    {
        cout << "Введите размерность матрицы:";
        cin >> n;
    }
    cout << "\nИсходный массив:\n\n";
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            cout << "  " << a[i][j];
        }
        cout << "\n";
    }
    for (int k(1); k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            for (int j = 0; j < n - k; j++)
            {
                if (a[i][j] > a[i + 1][j + 1])
                {
                    swap(a[i][j], a[i + 1][j + 1]);
                }
            }
        }
    }
    cout << "\nОтсортированный массив:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "  " << a[i][j];
        cout << "\n";
    }
    delete[]a;
    system("pause > null");
    return 0;
}
