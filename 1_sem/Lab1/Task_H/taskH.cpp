#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int rooms[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> rooms[i];
    }

    int k = n;
    if (n < 11)
    {
        for (int i = 0; i < n; i++)
        {
            int temp_k = 0;
            int start_room = rooms[i];

            for (int j = 0; j < n; j++)
            {
                int room_index = ((i + j) % n);
                if ((start_room & rooms[room_index]) != 0)
                {
                    start_room = rooms[room_index];
                    temp_k++;
                } else
                {
                    start_room += rooms[room_index];
                }
            }
            if (temp_k < k)
            {
                k = temp_k;
            }
        }
    } else
    {
        for (int i = 0; i < 19; i++)
        {
            int temp_k = 0;
            int start_room = rooms[i];

            for (int j = 0; j < n; j++)
            {
                int room_index = ((i + j) % n);
                if ((start_room & rooms[room_index]) != 0)
                {
                    start_room = rooms[room_index];
                    temp_k++;
                } else
                {
                    start_room += rooms[room_index];
                }
            }
            if (temp_k < k)
            {
                k = temp_k;
            }
        }
    }

    std::cout << k;
}