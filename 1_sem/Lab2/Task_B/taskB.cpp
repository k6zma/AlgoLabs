#include <iostream>

int med(int a, int b, int c) {
    if ((a > b) != (a > c))
        return a;
    else if ((b > a) != (b > c))
        return b;
    else
        return c;
}

void QSort(int a[], int left, int right)
{
    int i = left, j = right;
    int mid = (left + right) / 2;
    int key = med(a[left], a[mid], a[right]);
    int buf;

    do
    {
        while (a[i] < key)
        {
            i++;
        }
        while (a[j] > key)
        {
            j--;
        }
        if (i <= j)
        {
            buf = a[i];
            a[i] = a[j];
            a[j] = buf;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
    {
        QSort(a, left, j);
    }

    if (right > i)
    {
        QSort(a, i, right);
    }
}

int main()
{
    int n;
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    QSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
}