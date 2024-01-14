#include <iostream>

int main()
{
    unsigned long long x, y;
    std::cin >> x >> y;
    unsigned long long good_days = 0;
    for (int i = 1; i < 62; i++)
    {
        for (int j = 1; j < 62 - i; j++)
        {
            for (int m = 1; m < 62 - i - j; m++)
            {
                if (i + j + m < 64)
                {
                    unsigned long long final_number = 0;

                    for (int k = 0; k < i; k++) {
                        final_number = final_number << 1;
                        final_number = final_number + 1;
                    }

                    for (int k = 0; k < j; k++) {
                        final_number = final_number << 1;
                    }

                    for (int k = 0; k < m; k++) {
                        final_number = final_number << 1;
                        final_number = final_number + 1;
                    }

                    if (final_number >= x && final_number <= y)
                    {
                        good_days += 1;
                    }
                }
            }
        }
    }
    std::cout << good_days;
}