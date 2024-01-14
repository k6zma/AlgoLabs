#include <iostream>

void QSort(int a[], int left, int right, int stop_pos)
{
    int i = left, j = right;
    int mid = (left + right) / 2;
    int key = a[mid];
    int buf;
    if (left < right)
    {
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

        if (stop_pos <= j)
        {
            QSort(a, left, j, stop_pos);
        }

        if (i < stop_pos)
        {
            QSort(a, i, right, stop_pos);
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int c[n];
    int A, B, C;
    std::cin >> A >> B >> C >> c[0] >> c[1];

    for (int i = 2; i < n; i++) {
        c[i] = c[i - 2] * A + c[i - 1] * B + C;
    }

    QSort(c, 0, n - 1, k);

    int best_price = 0;
    for (int i = 0; i < k; i++) {
        best_price ^= c[i];
    }

    std::cout << best_price;
}