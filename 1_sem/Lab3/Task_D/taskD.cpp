#include <iostream>

struct Node
{
    Node* next = nullptr;
    Node* prev = nullptr;
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
            element->prev = tail;
            tail->next = element;
            tail = element;
        }

    }

    int pop_start()
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

    int pop_end()
    {
        Node* tmp = tail->prev;
        int tmp_value = tail->value;

        if (tail->prev != nullptr)
        {
            tail = tmp;
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

    int bottom()
    {
        return tail->value;
    }

    bool empty()
    {
        return head == nullptr;
    }
};

int main() {
    Queue q;

    int n, m;
    std::cin >> n >> m;

    if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            int item;
            std::cin >> item;
            q.push(item);
        }

        for (int i = m; i < n; i++)
        {
            int items[3];
            std::cin >> items[0];

            items[1] = q.top();
            items[2] = q.bottom();

            q.pop_start();
            q.pop_end();

            int temp;
            for (int j = 1; j < 3; j++)
            {
                int k;
                temp = items[j];
                for (k = j-1; k >= 0 && items[k] > temp; k--)
                {
                    items[k + 1] = items[k];
                }
                items[k+1] = temp;
            }

            q.push(items[1]);
            q.push(items[2]);
        }
    } else
    {
      for (int i = 0; i < n; i++)
      {
          int item;
          std::cin >> item;
          q.push(item);
      }
    }
    while(!q.empty())
    {
        std::cout << q.top() << " ";
        q.pop_start();
    }
}