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
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    Stack s;

    char symbol;
    int num;
    for (int i = 0; i < n; i++)
    {
        std::cin >> symbol;

        if (symbol == '+')
        {
            std::cin >> num;
            s.push(num);
        } else if (symbol == '-')
        {
            int temp = s.pop();
            std::cout << temp << "\n";
        }
    }
}