#include <iostream>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    bool av_e_s[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            av_e_s[i][j] = false;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int e, s;
        std::cin >> e >> s;
        av_e_s[s-1][e-1] = true;
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (av_e_s[i][j] == false)
            {
                k += 1;
            }
        }
    }

    std::cout << k << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (av_e_s[i][j] == false)
            {
                std::cout << j+1 << " " << i+1 << "\n";
            }
        }
    }
}