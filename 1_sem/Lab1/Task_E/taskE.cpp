#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    char string[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> string[i];
    }

    if (n <= 1)
    {
        std::cout << "NO";
        return 0;
    }

    int before = 0, after = n - 1, k = 0;
    while (before < after)
    {
        if (string[before] == string[after])
        {
            before++;
            after--;
        } else if (string[before] != string[after])
        {
            k++;
            if (string[before] == string[after-1])
            {
                after--;
            } else if (string[before+1] == string[after])
            {
                before++;
            }
        } if (k > 1)
        {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
}