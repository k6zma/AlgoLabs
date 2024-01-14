#include <iostream>
#include <string>

void CountingSort(long long A[], long long B[], std::string card_names[], std::string card_names_result[], long long n, long long k) {
    long long C[k];
    for (int i = 0; i < k; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    for (int j = 1; j < k; j++)
        C[j] += C[j - 1];

    for (int i = n - 1; i >= 0; i--) {
        C[A[i]]--;
        B[C[A[i]]] = A[i];
        card_names_result[C[A[i]]] = card_names[i];
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long n;
    std::cin >> n;

    long long cards_damage[n];
    long long result_cards_damage[n];

    std::string cards_name[n];
    std::string result_cards_name[n];

    long long max_card_damage = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;

        if (max_card_damage < temp)
        {
            max_card_damage = temp;
        }

        cards_damage[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> cards_name[i];
    }

    CountingSort(cards_damage, result_cards_damage, cards_name, result_cards_name, n, max_card_damage + 1);

    long long q;
    std::cin >> q;

    std::string request_name[q];
    long long request_range[q][2];
    for (int i = 0; i < q; i++)
    {
        std::cin >> request_name[i] >> request_range[i][0] >> request_range[i][1];
    }

    long long temp_sum[n + 1];
    long long temp_xor[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        temp_sum[i] = 0;
        temp_xor[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        temp_sum[i] = temp_sum[i - 1] + result_cards_damage[i - 1];
        temp_xor[i] = temp_xor[i - 1] ^ result_cards_damage[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << result_cards_damage[i];

        if (i != n - 1)
        {
            std::cout << " ";
        }
    }

    std::cout << "\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << result_cards_name[i];

        if (i != n - 1)
        {
            std::cout << " ";
        }
    }

    std::cout << "\n";

    for (int i = 0; i < q; i++)
    {
        long long left = 0, right = n - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (result_cards_damage[mid] < request_range[i][0])
            {
                left = mid + 1;
            } else
            {
                right = mid;
            }
        }

        long long L;
        L = left;

        left = 0, right = n - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (result_cards_damage[mid] <= request_range[i][1])
                left = mid + 1;
            else
                right = mid;
        }

        long long R;

        if (result_cards_damage[left] > request_range[i][1])
        {
            R = left - 1;
        } else {
            R = left;
        }

        if (request_name[i] == "Count")
        {
            if (L <= R)
            {
                std::cout << R - L + 1 << "\n";
            } else
            {
                std::cout << 0 << "\n";
            }
        }
        else if (request_name[i] == "Sum")
        {
            long long sum_of_damage = 0;
            sum_of_damage = temp_sum[R + 1] - temp_sum[L];
            std::cout << sum_of_damage << "\n";
        }
        else if (request_name[i] == "Xor")
        {
            long long xor_of_damage = 0;
            xor_of_damage = temp_xor[R + 1] ^ temp_xor[L];
            std::cout << xor_of_damage << "\n";
        }
    }
}