#include <iostream>

void merge(long a[], long b[], long left, long right, long mid)
{
    long it1 = 0, it2 = 0;
    long result[right - left];
    long temp_result[right - left];

    while ((left + it1 < mid) && (mid + it2 < right))
    {
        if (a[left + it1] >= a[mid + it2])
        {
            result[it1 + it2] = a[left + it1];
            temp_result[it1 + it2] = b[left + it1];
            it1++;
        } else
        {
            result[it1 + it2] = a[mid + it2];
            temp_result[it1 + it2] = b[mid + it2];
            it2++;
        }
    }
    while (left + it1 < mid)
    {
        result[it1 + it2] = a[left + it1];
        temp_result[it1 + it2] = b[left + it1];
        it1++;
    }
    while (mid + it2 < right)
    {
        result[it1 + it2] = a[mid + it2];
        temp_result[it1 + it2] = b[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++)
    {
        a[left + i] = result[i];
        b[left + i] = temp_result[i];
    }
}

void mergeSortRecursive(long a[], long b[], long left, long right)
{
    if (right - left > 1)
    {
        long mid = (left + right) / 2;

        mergeSortRecursive(a, b, left, mid);
        mergeSortRecursive(a, b, mid, right);

        merge(a, b, left, right, mid);
    }
}

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    long authority_factor[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> authority_factor[i];
    }

    long sum_points_per_film[m];
    long critic_assessment;
    for (int i = 0; i < m; i++)
    {
        sum_points_per_film[i] = 0;
        for (int j = 0; j < n; j++)
        {
            std::cin >> critic_assessment;
            sum_points_per_film[i] = (sum_points_per_film[i] + (critic_assessment * authority_factor[j])) % 1000000007;
        }
    }

    long number_of_film[m];
    for (int i = 0; i < m; i++)
    {
        number_of_film[i] = i;
    }

    mergeSortRecursive(sum_points_per_film, number_of_film, 0, m);

    for (int i = 0; i < k; i++)
    {
        std::cout << number_of_film[i] + 1 << " ";
    }
}
