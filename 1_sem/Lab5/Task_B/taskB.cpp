#include <iostream>
#include <string>

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

struct BST
{
    Node* root = nullptr;

    Node* exists(Node* x, int k)
    {
        if (x == nullptr || k == x->key)
        {
            return x;
        }

        if (k < x->key)
        {
            return exists(x->left, k);
        } else
        {
            return exists(x->right, k);
        }
    }

    Node* minimum(Node* x)
    {
        if (x->left == nullptr)
        {
            return x;
        }

        return minimum(x->left);
    }

    Node* maximum(Node* x)
    {
        if (x->right == nullptr)
        {
            return x;
        }

        return maximum(x->right);
    }

    Node* next(Node* root, int x)
    {
        Node* current = root;
        Node* successor = nullptr;

        while (current != nullptr)
        {
            if (current->key > x)
            {
                successor = current;
                current = current->left;
            } else
            {
                current = current->right;
            }
        }

        return successor;
    }

    Node* prev(Node* root, int x)
    {
        Node* current = root;
        Node* predecessor = nullptr;

        while (current != nullptr)
        {
            if (current->key < x)
            {
                predecessor = current;
                current = current->right;
            } else
            {
                current = current->left;
            }
        }

        return predecessor;
    }

    Node* insert(Node* x, int z)
    {
        if (x == nullptr)
        {
            Node* newNode = new Node;
            newNode->key = z;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (z < x->key)
        {
            x->left = insert(x->left, z);
        } else if (z > x->key)
        {
            x->right = insert(x->right, z);
        }

        return x;
    }

    Node* del(Node* root, int z)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (z < root->key)
        {
            root->left = del(root->left, z);
        } else if (z > root->key)
        {
            root->right = del(root->right, z);
        } else if (root->left != nullptr and root->right != nullptr)
        {
            root->key = minimum(root->right)->key;
            root->right = del(root->right, root->key);
        } else
        {
            if (root->left != nullptr)
            {
                root = root->left;
            } else if (root->right != nullptr)
            {
                root = root->right;
            } else
            {
                root = nullptr;
            }
        }

        return root;
    }

    void insertValueInBST(int x)
    {
        root = insert(root, x);
    }

    void delValueInBST(int x)
    {
        root = del(root, x);
    }

    Node* nextValueInBST(int x)
    {
        Node* temp = next(root, x);
        return temp;
    }

    Node* prevValueInBST(int x)
    {
        Node* temp = prev(root, x);
        return temp;
    }

    bool existValueInBst(int x)
    {
        Node* tempNode = exists(root, x);

        if (tempNode != nullptr)
        {
            return true;
        } else
        {
            return false;
        }
    }
};

int main()
{
    BST bst;

    std::string command;
    while (std::cin >> command)
    {
        if (command == "insert")
        {
            int x;
            std::cin >> x;

            bst.insertValueInBST(x);
        } else if (command == "delete")
        {
            int x;
            std::cin >> x;

            bst.delValueInBST(x);
        } else if (command == "next")
        {
            int x;
            std::cin >> x;

            Node* temp = bst.nextValueInBST(x);
            if (temp != nullptr)
            {
                std::cout << temp->key << "\n";
            } else
            {
                std::cout << "none" << "\n";
            }
        } else if (command == "prev")
        {
            int x;
            std::cin >> x;

            Node* temp = bst.prevValueInBST(x);
            if (temp != nullptr)
            {
                std::cout << temp->key << "\n";
            } else
            {
                std::cout << "none" << "\n";
            }
        } else if (command == "exists")
        {
            int x;
            std::cin >> x;

            bool temp = bst.existValueInBst(x);

            if (temp == true)
            {
                std::cout << "true" << "\n";
            } else
            {
                std::cout << "false" << "\n";
            }
        }
    }
}