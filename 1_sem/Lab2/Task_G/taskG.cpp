#include <iostream>

void merge(long a[][2], long left, long right, long mid)
{
    long it1 = 0, it2 = 0;
    long result[right - left][2];

    while ((left + it1 < mid) && (mid + it2 < right))
    {
        if (a[left + it1][0] <= a[mid + it2][0])
        {
            result[it1 + it2][0] = a[left + it1][0];
            result[it1 + it2][1] = a[left + it1][1];
            it1++;
        } else
        {
            result[it1 + it2][0] = a[mid + it2][0];
            result[it1 + it2][1] = a[mid + it2][1];
            it2++;
        }
    }
    while (left + it1 < mid)
    {
        result[it1 + it2][0] = a[left + it1][0];
        result[it1 + it2][1] = a[left + it1][1];
        it1++;
    }
    while (mid + it2 < right)
    {
        result[it1 + it2][0] = a[mid + it2][0];
        result[it1 + it2][1] = a[mid + it2][1];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++)
    {
        a[left + i][0] = result[i][0];
        a[left + i][1] = result[i][1];
    }
}

void mergeSortRecursive(long a[][2], long left, long right)
{
    if (right - left > 1)
    {
        long mid = (left + right) / 2;

        mergeSortRecursive(a, left, mid);
        mergeSortRecursive(a, mid, right);

        merge(a, left, right, mid);
    }
}

int main()
{
    long n;
    std::cin >> n;

    long labs[n][2];
    for (int i = 0; i < n; i++)
    {
        std::cin >> labs[i][0] >> labs[i][1];
    }

    mergeSortRecursive(labs, 0, n);

    long days = 0;
    long sum_of_points = 0;
    for (int i = 0; i < n; i++)
    {
        days += labs[i][0];
        sum_of_points += labs[i][1] - days;
    }

    std::cout << sum_of_points;
}