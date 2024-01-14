#include <iostream>

struct Node
{
    int key;
    Node* prev;
};

struct Stack
{
    Node* top = nullptr;

    void push(int elem)
    {
        Node* node = new Node();
        node->key = elem;
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

    int apex()
    {
        return top->key;
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

    Stack s_tasks;
    Stack s_index;

    int algo_tasks[n];
    int waiting_duration[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> algo_tasks[i];
        waiting_duration[i] = -1;
    }

    s_tasks.push(algo_tasks[0]);
    s_index.push(0);
    for (int i = 1; i < n; i++)
    {
        while ((s_tasks.empty() == false) && (s_tasks.apex() < algo_tasks[i]))
        {
            int temp_index = s_index.pop();
            waiting_duration[temp_index] = i - temp_index;
            s_tasks.pop();
        }
        s_tasks.push(algo_tasks[i]);
        s_index.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << waiting_duration[i] << " ";
    }
}