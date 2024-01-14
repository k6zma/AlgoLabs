#include <iostream>
#include <vector>

struct ShawermaMasterFeature
{
    long long shawerma_master_salary;
    long long shawerma_master_release_time;
};

struct free_priority_queue
{
    std::vector<ShawermaMasterFeature> data;

    void sift_up(long long index)
    {
        while (index != 0 && data[index].shawerma_master_salary < data[(index - 1) / 2].shawerma_master_salary)
        {
            long long parent_index = (index - 1) / 2;
            std::swap(data[index], data[parent_index]);
            index = parent_index;
        }
    }

    void sift_down(long long index)
    {
        while (2 * index + 1 < data.size())
        {
            long long left_child_index = 2 * index + 1;
            long long right_child_index = 2 * index + 2;
            long long smallest_child_index = index;

            if (left_child_index < data.size() && data[left_child_index].shawerma_master_salary < data[index].shawerma_master_salary)
            {
                smallest_child_index = left_child_index;
            }

            if (right_child_index < data.size() && data[right_child_index].shawerma_master_salary < data[smallest_child_index].shawerma_master_salary)
            {
                smallest_child_index = right_child_index;
            }

            if (smallest_child_index == index)
            {
                break;
            }

            std::swap(data[index], data[smallest_child_index]);
            index = smallest_child_index;
        }
    }

    void push(ShawermaMasterFeature value)
    {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    ShawermaMasterFeature extract_min()
    {
        ShawermaMasterFeature min_element = data[0];
        data[0] = data.back();
        data.pop_back();
        sift_down(0);
        return min_element;
    }

    bool is_empty()
    {
        return data.empty();
    }

    ShawermaMasterFeature top()
    {
        if (!data.empty())
        {
            return data[0];
        }
        return ShawermaMasterFeature{0, 0};
    }
};

struct busy_priority_queue
{
    std::vector<ShawermaMasterFeature> data;

    void sift_up(long long index)
    {
        while (index != 0 && data[index].shawerma_master_release_time < data[(index - 1) / 2].shawerma_master_release_time)
        {
            long long parent_index = (index - 1) / 2;
            std::swap(data[index], data[parent_index]);
            index = parent_index;
        }
    }

    void sift_down(long long index)
    {
        while (2 * index + 1 < data.size())
        {
            long long left_child_index = 2 * index + 1;
            long long right_child_index = 2 * index + 2;
            long long smallest_child_index = index;

            if (left_child_index < data.size() && data[left_child_index].shawerma_master_release_time < data[index].shawerma_master_release_time)
            {
                smallest_child_index = left_child_index;
            }

            if (right_child_index < data.size() && data[right_child_index].shawerma_master_release_time < data[smallest_child_index].shawerma_master_release_time)
            {
                smallest_child_index = right_child_index;
            }

            if (smallest_child_index == index)
            {
                break;
            }

            std::swap(data[index], data[smallest_child_index]);
            index = smallest_child_index;
        }
    }

    void push(ShawermaMasterFeature value)
    {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    ShawermaMasterFeature extract_min()
    {
        if (data.empty())
        {
            return ShawermaMasterFeature{0, 0};
        }

        ShawermaMasterFeature min_element = data[0];
        data[0] = data.back();
        data.pop_back();
        sift_down(0);
        return min_element;
    }

    bool is_empty()
    {
        return data.empty();
    }

    ShawermaMasterFeature top()
    {
        if (!data.empty())
        {
            return data[0];
        }
        return ShawermaMasterFeature{0, 0};
    }
};


int main()
{
    long long n, m;
    std::cin >> n >> m;

    free_priority_queue free_shawerma_masters;
    busy_priority_queue busy_shawerma_masters;
    for (int i = 0; i < n; i++)
    {
        long long salary;
        std::cin >> salary;
        free_shawerma_masters.push({salary, 0});
    }

    long long total_salary = 0;
    for (int i = 0; i < m; i++)
    {
        long long moment_of_order_receipt, cooking_time;
        std::cin >> moment_of_order_receipt >> cooking_time;

        while (!busy_shawerma_masters.is_empty() && busy_shawerma_masters.top().shawerma_master_release_time <= moment_of_order_receipt)
        {
            ShawermaMasterFeature possible_shawa_master = busy_shawerma_masters.extract_min();
            possible_shawa_master.shawerma_master_release_time = 0;
            free_shawerma_masters.push(possible_shawa_master);
        }

        if (!free_shawerma_masters.is_empty())
        {
            ShawermaMasterFeature best_vasya_shawa_master = free_shawerma_masters.extract_min();

            long long vasya_salary = best_vasya_shawa_master.shawerma_master_salary * cooking_time;
            total_salary += vasya_salary;

            best_vasya_shawa_master.shawerma_master_release_time = moment_of_order_receipt + cooking_time;
            busy_shawerma_masters.push(best_vasya_shawa_master);
        }
    }

    std::cout << total_salary;
}
