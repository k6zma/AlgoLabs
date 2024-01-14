#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int days[n], sum_of_days = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> days[i];
        sum_of_days += days[i];
    }

    int best_day = -1;
    int before_days = 0, after_days = sum_of_days - days[0];
    
    if (n <= 4)
    {
        std::cout << 0;
        return 0;
    } else
    {
        for (int i = 1; i < n; i++)
        {
            before_days += days[i-1];
            after_days -= days[i];

            if (before_days == after_days)
            {
                best_day = i;
                break;
            }
        }
    }
    std::cout << best_day;
}
