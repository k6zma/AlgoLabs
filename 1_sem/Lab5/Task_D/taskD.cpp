#include <iostream>
#include <vector>

struct Node {
    int key;
    int level;
    Node* left;
    Node* right;

    Node(int key, int level) : key(key), level(level), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root = nullptr;

    Node* insert(Node* node, int key, int level) {
        if (node == nullptr) {
            return new Node(key, level);
        }

        level++;

        if (key < node->key) {
            node->left = insert(node->left, key, level);
        } else if (key > node->key) {
            node->right = insert(node->right, key, level);
        }

        return node;
    }

    void customTravel(Node* node, std::vector<int>& max_rights_result) {
        if (node == nullptr) {
            return;
        }

        if (max_rights_result.size() <= node->level) {
            max_rights_result.push_back(node->key);
        } else {
            int level_index = node->level;
            max_rights_result[level_index] = node->key;
        }

        customTravel(node->left, max_rights_result);
        customTravel(node->right, max_rights_result);
    }
};

int main() {
    int n;
    std::cin >> n;

    Tree tree;

    for (int i = 0; i < n; i++) {
        int key;
        std::cin >> key;
        tree.root = tree.insert(tree.root, key, 0);
    }

    std::vector<int> max_rights_result;
    tree.customTravel(tree.root, max_rights_result);

    for (int i = 0; i < max_rights_result.size(); i++) {
        std::cout << max_rights_result[i] << " ";
    }
}
