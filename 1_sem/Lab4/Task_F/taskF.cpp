#include <iostream>
#include <vector>

struct PrimeAndPower
{
    unsigned long long prime_num;
    unsigned long long power;
};

struct MinHeap
{
    std::vector<PrimeAndPower> data;

    void sift_up(unsigned long long index)
    {
        while (index != 0 && data[index].prime_num < data[(index - 1) / 2].prime_num)
        {
            unsigned long long parent_index = (index - 1) / 2;
            if (data[index].prime_num < data[parent_index].prime_num)
            {
                std::swap(data[index], data[parent_index]);
                index = parent_index;
            } else
            {
                break;
            }
        }
    }

    void sift_down(unsigned long long index)
    {
        while (2 * index + 1 < data.size())
        {
            unsigned long long left_child_index = 2 * index + 1;
            unsigned long long right_child_index = 2 * index + 2;
            unsigned long long smallest_child_index = left_child_index;

            if (right_child_index < data.size() && data[right_child_index].prime_num < data[left_child_index].prime_num)
            {
                smallest_child_index = right_child_index;
            }

            if (data[index].prime_num <= data[smallest_child_index].prime_num)
            {
                break;
            }

            std::swap(data[index], data[smallest_child_index]);
            index = smallest_child_index;
        }
    }

    void push(PrimeAndPower value)
    {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    PrimeAndPower extract_min()
    {
        PrimeAndPower min_element = data[0];

        data[0] = data.back();
        data.pop_back();

        sift_down(0);

        return min_element;
    }

    void build_heap()
    {
        for (int i = data.size() / 2 - 1; i >= 0; i--)
        {
            sift_down(i);
        }
    }

    void generate_prime_nums(unsigned long long n)
    {
        if (n < 2) return;

        std::vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (unsigned long long p = 2; p * p < n; p++)
        {
            if (prime[p])
            {
                for (unsigned long long i = p * p; i < n; i += p)
                    prime[i] = false;
            }
        }

        for (unsigned long long p = 2; p < n; p++)
        {
            if (prime[p])
            {
                data.push_back({p, p});
            }
        }
    }
};

std::vector<unsigned long long> factorize(unsigned long long &n)
{
    MinHeap heap1;
    heap1.generate_prime_nums(5000000);

    std::vector<unsigned long long> final_factors;

    for (unsigned long long i = 0; i < n; i++)
    {
        PrimeAndPower top = heap1.extract_min();

        unsigned long long current = top.prime_num;
        while (current % top.power == 0)
        {
            final_factors.push_back(top.power);
            current /= top.power;
        }

        heap1.push({top.prime_num * top.prime_num, top.power});
    }

    std::sort(final_factors.begin(), final_factors.end());
    return final_factors;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    unsigned long long n;
    std::cin >> n;

    std::vector<unsigned long long> result = factorize(n);
    std::cout << result.size() << "\n";
    for (unsigned long long i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
}