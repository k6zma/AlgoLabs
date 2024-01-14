#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

struct BST
{
    Node* root = nullptr;

    void insert(int z)
    {
        root = insert_make(root, z);
    }

    Node* insert_make(Node* x, int z)
    {
        if (x == nullptr)
        {
            x = new Node;
            x->key = z;
            return x;
        } else if (z < x->key)
        {
            x->left = insert_make(x->left, z);
        } else if (z > x->key)
        {
            x->right = insert_make(x->right, z);
        }
        return x;
    }

    Node* bst_biuld(std::vector<int>& arr, int start, int end) {
        
        if (start > end) 
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        Node* node = new Node;
        node->key = arr[mid];
        node->left = bst_biuld(arr, start, mid - 1);
        node->right = bst_biuld(arr, mid + 1, end);

        return node;
    }

    void preorderTravel(Node* x)
    {
        if (x != nullptr)
        {
            std::cout << x->key << " ";
            preorderTravel(x->left);
            preorderTravel(x->right);
        }
    }
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> temp_vector;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        temp_vector.push_back(temp);
    }

    BST bst;
    bst.root = bst.bst_biuld(temp_vector, 0, n - 1);

    bst.preorderTravel(bst.root);
}