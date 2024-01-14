#include <iostream>

int main()
{
    int N, K;
    std::cin >> N >> K;

    K %= N;

    int numbers[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> numbers[i];
    }

    if (K > 0)
    {
        for (int i = 0; i < K; i++)
        {
            int temp_num = numbers[N-1];
            for (int j = (N - 2); j >= 0; j--)
            {
                numbers[j+1] = numbers[j];
            }
            numbers[0] = temp_num;
        }
    } else if (K < 0)
    {
        for (int i = 0; i < abs(K); i++)
        {
            int temp_num = numbers[0];
            for (int j = 0; j <= (N - 2); j++)
            {
                numbers[j] = numbers[j+1];
            }
            numbers[N-1] = temp_num;
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << numbers[i] << " ";
    }

    return 0;
}