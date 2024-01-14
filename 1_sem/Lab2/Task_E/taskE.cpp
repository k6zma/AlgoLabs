#include <iostream>

long k = 0;

void merge(int a[], int left, int right, int mid)
{
    int it1 = 0, it2 = 0;
    int result[right - left];

    while ((left + it1 < mid) && (mid + it2 < right))
    {
        if (a[left + it1] <= a[mid + it2])
        {
            result[it1 + it2] = a[left + it1];
            it1++;
        } else
        {
            result[it1 + it2] = a[mid + it2];
            it2++;
            k += mid - left - it1;
        }
    }
    while (left + it1 < mid)
    {
        result[it1 + it2] = a[left + it1];
        it1++;
    }
    while (mid + it2 < right)
    {
        result[it1 + it2] = a[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++)
    {
        a[left + i] = result[i];
    }
}

void mergeSortRecursive(int a[], int left, int right)
{
    if (right - left > 1)
    {
        int mid = (left + right) / 2;

        mergeSortRecursive(a, left, mid);
        mergeSortRecursive(a, mid, right);

        merge(a, left, right, mid);
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

    mergeSortRecursive(a, 0, n);

    std::cout << k;
}
