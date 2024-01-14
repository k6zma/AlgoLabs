#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int min_points = 15;
        int max_points = 30;
        
        int n;
        std::cin >> n;

        for (int j = 0; j < n; j++)
        {
            char sign, temp_sign;
            int points;

            std::cin >> sign >> temp_sign >> points;

            if ((sign == '<') && (points < max_points))
            {
                max_points = points;
            } else if ((sign == '>') && (points > min_points))
            {
                min_points = points;
            }

            if (min_points <= max_points)
            {
                std::cout << min_points << "\n";
            } else
            {
                std::cout << -1 << "\n";
            }
        }
    }
}