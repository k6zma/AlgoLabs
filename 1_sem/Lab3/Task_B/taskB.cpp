#include <iostream>

struct Node
{
    Node* next = nullptr;
    int value;
};

struct Queue
{
    Node* head = nullptr;
    Node* tail = nullptr;

    void push(int value)
    {
        Node* element = new Node;
        element->value = value;

        if (tail == nullptr && head == nullptr)
        {
            head = element;
            tail = element;
        } else
        {
            tail->next = element;
            tail = element;
        }

    }

    int pop()
    {
        Node* tmp = head->next;
        int tmp_value = head->value;

        if (head->next != nullptr)
        {
            head = tmp;
        } else {
            head = nullptr;
            tail = nullptr;
        }

        return tmp_value;
    }

    int top()
    {
        return head->value;
    }

    bool empty()
    {
        return head == nullptr;
    }
};

int main()
{
    std:: ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    Queue q;

    int n;
    std::cin >> n;

    char symbol;
    int num;
    for (int i = 0; i < n; i++)
    {
        std::cin >> symbol;

        if (symbol == '+')
        {
            std::cin >> num;
            q.push(num);
        } else if (symbol == '-')
        {
            int temp = q.pop();
            std::cout << temp << "\n";
        }
    }
}