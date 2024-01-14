#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int horses[n];
    for (int i = 0; i < n; i++) {
        std::cin >> horses[i];
    }

    int temp;
    for (int i = n - 1; i >= 0; i--)
    {
        int j;
        temp = horses[i];
        for (j = i + 1; j < n && horses[j] < temp; j++)
        {
            int dist_between_horses = j - i;
            int tugriks_after_replacement = temp -  horses[j];

            if (tugriks_after_replacement == 1)
            {
                std::cout << ":(";
                return 0;
            }

            horses[j - 1] = horses[j] + 1;
            temp--;
        }
        horses[j - 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << horses[i] << " ";
    }
}
