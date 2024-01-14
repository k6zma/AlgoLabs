#include <iostream>

struct Node
{
    int key;
    int index;
    Node* prev;
};

struct Stack
{
    Node* top = nullptr;

    void push(int elem, int index)
    {
        Node* node = new Node();
        node->key = elem;
        node->index = index;
        node->prev = top;
        top = node;
    }

    int pop()
    {
        Node* node = top;
        int value = node->key;
        top = top->prev;

        return value;
    }

    int head()
    {
        return top->key;
    }

    int current_index()
    {
        return top->index;
    }

    bool empty()
    {
        return top == nullptr;
    }
};

int main()
{
    int n;
    std::cin >> n;

    Stack s;
    long best_area = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;

        while (s.empty() != true && s.head() >= temp)
        {
            long current_wood_height = s.pop();
            long current_width = 0, current_area = 0;

            if (s.empty() != true)
            {
                int current_wood_index = s.current_index();
                current_width = i - current_wood_index - 1;
            } else
            {
                current_width = i;
            }

            current_area = current_width * current_wood_height;
            if (best_area < current_area)
            {
                best_area = current_area;
            }
        }

        s.push(temp, i);
    }

    while (s.empty() != true)
    {
        long current_wood_height = s.pop();
        long current_width = 0, current_area = 0;

        if (s.empty() != true)
        {
            int current_wood_index = s.current_index();
            current_width = n - current_wood_index - 1;
        } else
        {
            current_width = n;
        }

        current_area = current_width * current_wood_height;
        if (best_area < current_area)
        {
            best_area = current_area;
        }
    }
    std::cout << best_area;
}

