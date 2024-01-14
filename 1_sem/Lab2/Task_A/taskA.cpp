#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    
    int boots[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> boots[i];
    }
    
    int temp;
    for (int i = 1; i < n; i++)
    {
        int j;
        temp = boots[i];
        for (j = i-1; j >= 0 && boots[j] > temp; j--)
        {
            boots[j + 1] = boots[j];
        }
        boots[j+1] = temp;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << boots[i] << " ";
    }
}