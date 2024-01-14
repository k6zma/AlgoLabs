#include <iostream>
#include <vector>

struct Node {
    int key;
    int height;
    int index_of_node;
    int balance_of_sub;
    Node* left;
    Node* right;

    Node(int value_of_node) : key(value_of_node), height(0), index_of_node(0), balance_of_sub(0), left(nullptr), right(nullptr) {}
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

    Node* nodeTreeBalancing(Node* node) {
        if (node == nullptr) {
            return node;
        }

        int temp_height = calcHeightAndUpdateBalance(node);

        if (node->balance_of_sub > 1) {
            int balance_of_left_subtree = node->left->balance_of_sub;

            if (balance_of_left_subtree < 0) {
                node = bigRightRotate(node);
            } else {
                node = smallRightRotate(node);
            }
        } else if (node->balance_of_sub < -1) {
            int balance_of_right_subtree = node->right->balance_of_sub;

            if (balance_of_right_subtree > 0) {
                node = bigLeftRotate(node);
            } else {
                node = smallLeftRotate(node);
            }
        }

        return node;
    }

    Node* insert(Node* node, Node* node_for_insert) {
        if (node == nullptr) {
            return node_for_insert;
        }

        if (node->key < node_for_insert->key) {
            node->right = insert(node->right, node_for_insert);
        } else if (node->key > node_for_insert->key) {
            node->left = insert(node->left, node_for_insert);
        }

        node = nodeTreeBalancing(node);

        return node;
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

    Node* allTreeBalancing(Node* node) {
        if (node == nullptr) {
            return node;
        }

        Node* left_child = node->left;
        Node* right_child = node->right;

        if (left_child != nullptr) {
            allTreeBalancing(left_child);
        }

        if (right_child != nullptr) {
            allTreeBalancing(right_child);
        }

        node = nodeTreeBalancing(node);

        return node;
    }
};


int main() {
    int n;
    std::cin >> n;

    if (n != 0) {
        AvlTree avl_tree;
        std::vector<Node*> avl_nodes_data;

        std::vector<Childrens> chilrens;

        int parent_value, left_index, right_index;
        for (int i = 0; i < n; i++) {
            std::cin >> parent_value >> left_index >> right_index;

            Node* value_of_node = new Node(parent_value);
            avl_nodes_data.push_back(value_of_node);

            chilrens.push_back({left_index, right_index});
        }

        int num_for_insert;
        std::cin >> num_for_insert;

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

        Node* node_for_insert = new Node(num_for_insert);
        root = avl_tree.insert(root, node_for_insert);

        root = avl_tree.allTreeBalancing(root);

        int temp_index = 1;
        avl_tree.updatingIndexing(root, temp_index);

        std::cout << n + 1 << "\n";

        int temp_count = 0;
        avl_tree.customTreeTravel(root);
    } else {
        int num_for_insert;
        std::cin >> num_for_insert;
        std::cout << n + 1 << "\n";
        std::cout << num_for_insert << " " << 0 << " " << 0;
    }
}