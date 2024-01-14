#include <iostream>

struct Node
{
    int value;
    Node* next = nullptr;
};

struct List
{
    Node* head = nullptr;

    Node* cycle_check()
    {
        Node *turtle = head;
        Node *hare = head;
        do
        {
            if (hare == nullptr || hare->next == nullptr || hare == hare->next)
            {
                return nullptr;
            }
            turtle = turtle->next;
            hare = hare->next->next;
        } while (turtle != hare);

        if (hare == hare->next)
        {
            return nullptr;
        }

        return hare;
    }

    int cycle_length_check(Node* point_of_meeting)
    {
        if (point_of_meeting == nullptr)
        {
            return -1;
        }

        int length = 1;
        Node* hare = point_of_meeting->next;
        while (point_of_meeting != hare)
        {
            hare = hare->next;
            length++;
        }

        return length;
    }
};

int main()
{
    int n;
    std::cin >> n;

    List list;
    Node* nodes = new Node[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> nodes[i].value;
        if (i == 0) {
            list.head = &nodes[i];
        } else {
            nodes[i - 1].next = &nodes[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int index = nodes[i].value - 1;
        if (index >= 0 && index < n)
        {
            nodes[i].next = &nodes[index];
        }
    }

    Node* point_of_meeting = list.cycle_check();
    std::cout << list.cycle_length_check(point_of_meeting);
}
