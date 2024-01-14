#include <iostream>
#include <vector>

struct Node {
    int key;
    int height;
    int index_of_node;
    int balance_of_sub;
    Node* left;
    Node* right;

    Node(int value_of_node, int index) : key(value_of_node), height(1), index_of_node(index + 1), left(nullptr), right(nullptr) {}
};

struct Childrens {
    int left;
    int right;
};

struct AvlTree {
    int calcHeightAndUpdateBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int height_of_left_subtree = calcHeightAndUpdateBalance(node->left);
        int height_of_right_subtree = calcHeightAndUpdateBalance(node->right);

        node->balance_of_sub = height_of_left_subtree - height_of_right_subtree;

        int current_height = std::max(height_of_left_subtree, height_of_right_subtree) + 1;

        return current_height;
    }

    Node* smallLeftRotate(Node* a) {
        Node* b = a->right;

        a->right = b->left;
        b->left = a;

        calcHeightAndUpdateBalance(b);
        calcHeightAndUpdateBalance(a);

        return b;
    }

    Node* smallRightRotate(Node* a) {
        Node* b = a->left;

        a->left = b->right;
        b->right = a;

        calcHeightAndUpdateBalance(b);
        calcHeightAndUpdateBalance(a);

        return b;
    }

    Node* bigLeftRotate(Node* node) {
        node->right = smallRightRotate(node->right);
        return smallLeftRotate(node);
    }

    Node* bigRightRotate(Node* node) {
        node->left = smallLeftRotate(node->left);
        return smallRightRotate(node);
    }

    void updatingIndexing(Node* node, int& index) {
        if (node == nullptr) {
            return;
        }

        node->index_of_node = index;
        index++;

        updatingIndexing(node->left, index);
        updatingIndexing(node->right, index);
    }

    void customTreeTravel(Node* tree) {
        if (tree == nullptr) {
            return;
        }
        int left_son_index, right_son_index;

        if (tree->left != nullptr) {
            left_son_index = tree->left->index_of_node;
        } else {
            left_son_index = 0;
        }

        if (tree->right != nullptr) {
            right_son_index = tree->right->index_of_node;
        } else {
            right_son_index = 0;
        }

        std::cout << tree->key << " " << left_son_index << " " << right_son_index << "\n";

        customTreeTravel(tree->left);
        customTreeTravel(tree->right);
    }
};


int main() {
    int n;
    std::cin >> n;

    AvlTree avl_tree;
    std::vector<Node*> avl_nodes_data;

    std::vector<Childrens> chilrens;

    int parent_value, left_index, right_index;
    for (int i = 0; i < n; i++) {
        std::cin >> parent_value >> left_index >> right_index;

        Node* value_of_node = new Node(parent_value, i);
        avl_nodes_data.push_back(value_of_node);

        chilrens.push_back({left_index, right_index});
    }

    for (int i = 0; i < n; i++) {
        if (chilrens[i].right != 0) {
            avl_nodes_data[i]->right = avl_nodes_data[chilrens[i].right - 1];
        } else {
            avl_nodes_data[i]->right = nullptr;
        }

        if (chilrens[i].left != 0) {
            avl_nodes_data[i]->left = avl_nodes_data[chilrens[i].left - 1];
        } else {
            avl_nodes_data[i]->left = nullptr;
        }
    }
    Node* root = avl_nodes_data[0];
    avl_tree.calcHeightAndUpdateBalance(root);

    Node* right_subtree = root->right;
    if (right_subtree->balance_of_sub != 1)
    {
        root = avl_tree.smallLeftRotate(root);
    }
    else
    {
        root = avl_tree.bigLeftRotate(root);
    }

    int temp_index = 1;
    avl_tree.updatingIndexing(root, temp_index);

    std::cout << n << "\n";
    avl_tree.customTreeTravel(root);
}