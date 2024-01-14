#include <iostream>
#include <vector>

struct CityFeature
{
    int city_index;
    int city_feature;
};

bool check_rating(const CityFeature& a, const CityFeature& b) {
    return ((a.city_feature > b.city_feature) || (a.city_feature == b.city_feature && a.city_index > b.city_index));
}

bool check_fee(const CityFeature& a, const CityFeature& b)
{
    return ((a.city_feature > b.city_feature) || (a.city_feature == b.city_feature && a.city_index > b.city_index));
}

struct MaxHeapRating
{
    std::vector<CityFeature> data;

    void buildHeap(std::vector<CityFeature> &a)
    {
        data = a;
        for (int i = data.size() - 1; i >= 0; --i)
        {
            siftDown(i, data.size());
        }
    }

    void siftUp(int i)
    {
        while (i != 0 && check_rating(data[i], data[(i - 1) / 2]))
        {
            std::swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void siftDown(int i, int heap_size)
    {
        while (2 * i + 1 < heap_size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int temp = i;

            if (left < heap_size && check_rating(data[left], data[temp]))
            {
                temp = left;
            }

            if (right < heap_size && check_rating(data[right], data[temp]))
            {
                temp = right;
            }

            if (temp != i)
            {
                std::swap(data[i], data[temp]);
                i = temp;
            } else
            {
                break;
            }
        }
    }

    void insert(CityFeature el)
    {
        data.push_back(el);
        siftUp(data.size() - 1);
    }

    CityFeature extractMax()
    {
        CityFeature max = data[0];
        data[0] = data.back();
        data.pop_back();
        siftDown(0, data.size());
        return max;
    }

    CityFeature getMax()
    {
        return data[0];
    }
};

struct MaxHeapFee
{
    std::vector<CityFeature> data;

    void buildHeap(std::vector<CityFeature> &a)
    {
        data = a;
        for (int i = data.size() - 1; i >= 0; --i)
        {
            siftDown(i, data.size());
        }
    }

    void siftUp(int i)
    {
        while (i != 0 && check_fee(data[i], data[(i - 1) / 2]))
        {
            std::swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void siftDown(int i, int heap_size)
    {
        while (2 * i + 1 < heap_size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int temp = i;

            if (left < heap_size && check_fee(data[left], data[temp]))
            {
                temp = left;
            }

            if (right < heap_size && check_fee(data[right], data[temp]))
            {
                temp = right;
            }

            if (temp != i)
            {
                std::swap(data[i], data[temp]);
                i = temp;
            } else
            {
                break;
            }
        }
    }

    void insert(CityFeature el)
    {
        data.push_back(el);
        siftUp(data.size() - 1);
    }

    CityFeature extractMax()
    {
        CityFeature max = data[0];
        data[0] = data.back();
        data.pop_back();
        siftDown(0, data.size());
        return max;
    }

    CityFeature getMax()
    {
        return data[0];
    }
};

int main()
{
    int n;
    std::cin >> n;

    MaxHeapRating rating_heap;
    MaxHeapFee fee_heap;

    for (int i = 0; i < n; i++)
    {
        int city_number, city_rating, fee;
        std::cin >> city_number >> city_rating >> fee;

        rating_heap.insert({city_number, city_rating});
        fee_heap.insert({city_number, fee});
    }

    int m;
    std::cin >> m;
    std::string trade_statement[m];
    for (int i = 0; i < m; i++)
    {
        std::cin >> trade_statement[i];
    }

    std::vector<int> city_with_show;
    std::vector<int> city_with_trade;
    int temp_m = m;
    for (int i = 0; i < n; i++)
    {
        int max_rating = rating_heap.getMax().city_feature;
        int max_rating_index = rating_heap.getMax().city_index;
        int max_fee = fee_heap.getMax().city_feature;
        int max_fee_index = fee_heap.getMax().city_index;

        if (max_rating_index == max_fee_index)
        {
            city_with_show.push_back(max_rating_index);
            rating_heap.extractMax();
            fee_heap.extractMax();
        } else
        {
            if (temp_m != 0)
            {
                city_with_trade.push_back(max_rating_index);
                if (trade_statement[m - temp_m] == "YES")
                {
                    city_with_show.push_back(max_rating_index);
                    rating_heap.extractMax();
                } else if (trade_statement[m - temp_m] == "NO")
                {
                    rating_heap.extractMax();
                }

                temp_m--;
            } else
            {
                rating_heap.extractMax();
            }
        }
    }

    for (int i = 0; i < city_with_trade.size(); i++)
    {
        std::cout << city_with_trade[i] << " ";
    }

    std::cout << "\n";

    for (int i = 0; i < city_with_show.size(); i++)
    {
        std::cout << city_with_show[i] << " ";
    }
}