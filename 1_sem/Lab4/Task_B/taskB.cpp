#include <iostream>
#include <vector>
#include <string>

struct priority_queue
{
    std::vector<int> data;

    void sift_up(int index)
    {
        while (index != 0 && data[index] < data[(index - 1) / 2])
        {
            int parent_index = (index - 1) / 2;
            if (data[index] < data[parent_index])
            {
                std::swap(data[index], data[parent_index]);
                index = parent_index;
            } else
            {
                break;
            }
        }
    }

    void sift_down(int index)
    {
        while (2 * index + 1 < data.size())
        {
            int left_child_index = 2 * index + 1;
            int right_child_index = 2 * index + 2;
            int smallest_child_index = left_child_index;

            if (right_child_index < data.size() && data[right_child_index] < data[left_child_index])
            {
                smallest_child_index = right_child_index;
            }

            if (data[index] <= data[smallest_child_index])
            {
                break;
            }

            std::swap(data[index], data[smallest_child_index]);
            index = smallest_child_index;
        }
    }

    void push(int value)
    {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    int extract_min()
    {
        int min_element = data[0];

        data[0] = data.back();
        data.pop_back();

        sift_down(0);

        return min_element;
    }

    bool check_if_queue_empty()
    {
        return data.empty();
    }

    void build_heap()
    {
        for (int i = data.size() / 2 - 1; i >= 0; i--)
        {
            sift_down(i);
        }
    }

    void queue_merge(priority_queue &a, priority_queue &b)
    {
        for (int i = 0; i < a.data.size(); i++)
        {
            data.push_back(a.data[i]);
        }

        for (int i = 0; i < b.data.size(); i++)
        {
            data.push_back(b.data[i]);
        }

        build_heap();
    }

    void decrease_key(int x, int y)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == x)
            {
                data[i] = y;
                sift_up(i);
                break;
            }
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<priority_queue> priority_queues;

    std::string command;
    while (std::cin >> command)
    {
        if (command == "create")
        {
            priority_queue new_queue;
            priority_queues.push_back(new_queue);
        } else if (command == "insert")
        {
            int k, x;
            std::cin >> k >> x;

            if (k < priority_queues.size())
            {
                priority_queues[k].push(x);
            }
        } else if (command == "extract-min")
        {
            int k;
            std::cin >> k;

            if (!priority_queues[k].check_if_queue_empty())
            {
                std::cout << priority_queues[k].extract_min() << "\n";
            } else
            {
                std::cout << "*" << "\n";
            }
        } else if (command == "merge")
        {
            int k, m;
            std::cin >> k >> m;

            priority_queue new_queue;

            new_queue.queue_merge(priority_queues[k], priority_queues[m]);
            priority_queues.push_back(new_queue);
        } else if (command == "decrease-key")
        {
            int k, x, y;
            std::cin >> k >> x >> y;

            priority_queues[k].decrease_key(x, y);
        }
    }
}
