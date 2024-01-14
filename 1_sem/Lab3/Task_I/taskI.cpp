#include <iostream>

void merge(long long a[], long long left, long long right, long long mid)
{
    long long it1 = 0, it2 = 0;
    long long result[right - left];

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

void mergeSortRecursive(long long a[], long long left, long long right)
{
    if (right - left > 1)
    {
        long long mid = (left + right) / 2;

        mergeSortRecursive(a, left, mid);
        mergeSortRecursive(a, mid, right);

        merge(a, left, right, mid);
    }
}


int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long n, k;
    std::cin >> n >> k;

    long long man_coeff[n], woman_coeff[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> man_coeff[i];
    }
    for (int j = 0; j < n; j++)
    {
        std::cin >> woman_coeff[j];
    }

    mergeSortRecursive(man_coeff, 0, n);
    mergeSortRecursive(woman_coeff, 0, n);

    long long left = man_coeff[0] + woman_coeff[0];
    long long right = man_coeff[n-1] + woman_coeff[n-1];
    long long result = -1;

    while (left < right) {
        long long mid = (left + right) / 2;

        long long temp_count = 0;
        long long j = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (j < n && woman_coeff[j] + man_coeff[i] <= mid) {
                j++;
            }
            temp_count += j;
        }

        if (temp_count < k) {
            left = mid + 1;
            result = left;
        } else {
            right = mid;
        }
    }
    std::cout << result;
}