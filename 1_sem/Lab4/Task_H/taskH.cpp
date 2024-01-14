#include <iostream>

void sum_temp(char* num1, std::string num2)
{
    int length_of_num1 = 1024;
    int length_of_num2 = num2.size();

    int temp_num_for_transfer = 0;
    for (int i = length_of_num2 - 1; i >= 0 || temp_num_for_transfer != 0; i--) 
    {
        int num_from_char_to_digit = temp_num_for_transfer;
        
        if (length_of_num2 - 1 - i < length_of_num1) 
        {
            num_from_char_to_digit += num1[length_of_num2 - 1 - i];
        }
        if (i >= 0) 
        {
            num_from_char_to_digit += num2[i] - 48;
        }

        if (length_of_num2 - 1 - i < length_of_num1) 
        {
            num1[length_of_num2 - 1 - i] = num_from_char_to_digit % 10;
        }
        
        temp_num_for_transfer = num_from_char_to_digit / 10;
    }
}

int main()
{
    int n;
    std::cin >> n;

    char sum[1024];
    for (int i = 0; i < 1024; i++)
    {
        sum[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        std::string num;
        std::cin >> num;

        sum_temp(sum, num);
    }

    int i = 1023;
    while (i > 0 && sum[i] == 0) 
    {
        i--;
    }

    std::string final_num;
    while (i >= 0)
    {
        final_num += sum[i] + 48;
        i--;
    }

    std::cout << final_num;
}