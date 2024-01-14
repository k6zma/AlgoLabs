#include <iostream>

void QSort(int a[], int left, int right)
{
    int i = left, j = right;
    int mid = (left + right) / 2;
    int key = a[mid];
    int buf;

    while (i <= j)
    {
        while (a[i] > key)
        {
            i++;
        }
        while (a[j] < key)
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
    }

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

    int sticks[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> sticks[i];
    }

    QSort(sticks, 0, n - 1);

    long best_sticks[n];
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (sticks[i] - sticks[i+1] < 2)
        {
            best_sticks[k] = sticks[i+1];
            k++;
            i++;
        }
    }

    long area = 0;
    for (int i = 0; i < k - 1; i += 2)
    {
        area += best_sticks[i] * best_sticks[i+1];
    }
    std::cout << area;
}