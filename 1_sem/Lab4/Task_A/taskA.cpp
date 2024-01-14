#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> data;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;

        data.push_back(temp);
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (2 * i + 1 < n)
        {
            if (data[i] <= data[2 * i + 1])
            {
                continue;
            } else
            {
                flag = false;
                break;
            }
        }

        if (2 * i + 2 < n)
        {
            if (data[i] <= data[2 * i + 2])
            {
                continue;
            } else
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        std::cout << "YES";
    } else
    {
        std::cout << "NO";
    }
}