#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string key;
    int height;
    int repeat_words_count;
    int unique_symbols_count;
    Node* left;
    Node* right;

    int countUniqueSymbolsInWord(std::string& str) {
        std::vector<bool> checked_symbols(128, false);
        int count = 0;

        for (int i = 0; i < str.length(); i++) {
            unsigned char string_symbol = (unsigned char)(str[i]);

            if (!checked_symbols[string_symbol]) {
                checked_symbols[string_symbol] = true;
                count++;
            }
        }

        return count;
    }

    Node(std::string key) : key(key), height(1), left(nullptr), right(nullptr), repeat_words_count(1), unique_symbols_count(countUniqueSymbolsInWord(key)) {}
};

struct AVLTree {
    Node* root = nullptr;

    int calcHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int calcBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return calcHeight(node->left) - calcHeight(node->right);
    }

    void fixHeightNode(Node* node) {
        if (node == nullptr) {
            return;
        }

        int current_subtree_height = std::max(calcHeight(node->left), calcHeight(node->right)) + 1;
        node->height = current_subtree_height;
    }

    Node* smallRightRotate(Node* a) {
        Node* b = a->left;
        a->left = b->right;
        b->right = a;

        fixHeightNode(a);
        fixHeightNode(b);

        return b;
    }

    Node* smallLeftRotate(Node* a) {
        Node* b = a->right;
        a->right = b->left;
        b->left = a;

        fixHeightNode(a);
        fixHeightNode(b);

        return b;
    }

    Node* bigRightRotate(Node* node) {
        node->left = smallLeftRotate(node->left);
        return smallRightRotate(node);
    }

    Node* bigLeftRotate(Node* node) {
        node->right = smallRightRotate(node->right);
        return smallLeftRotate(node);
    }

    Node* balanceNode(Node* node) {
        if (node == nullptr) {
            return node;
        }

        fixHeightNode(node);

        int balance_factor = calcBalanceFactor(node);
        if (balance_factor > 1) {
            int balance_factor_left = calcBalanceFactor(node->left);
            if (balance_factor_left < 0) {
                return bigRightRotate(node);
            } else {
                return smallRightRotate(node);
            }
        } else if (balance_factor < -1) {
            int balance_factor_right = calcBalanceFactor(node->right);
            if (balance_factor_right > 0) {
                return bigLeftRotate(node);
            } else {
                return smallLeftRotate(node);
            }
        }

        return node;
    }

    Node* insert(Node* node, std::string key) {
        if (node == nullptr) {
            Node* newNode = new Node(key);
            return newNode;
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            node->repeat_words_count++;
            return node;
        }

        node = balanceNode(node);
        return node;
    }

    int calcResult(Node* node) {
        if (node == nullptr) return 0;

        int left_subtree_res = calcResult(node->left);
        int right_subtree_res = calcResult(node->right);

        int count_of_repeat_words = node->repeat_words_count;
        if (count_of_repeat_words > 1) {
            return left_subtree_res + right_subtree_res + (count_of_repeat_words - 1) * node->unique_symbols_count;
        } else {
            return left_subtree_res + right_subtree_res;
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    AVLTree avl_tree;

    for (int i = 0; i < n; ++i) {
        std::string contact_string;
        std::cin >> contact_string;

        avl_tree.root = avl_tree.insert(avl_tree.root, contact_string);
    }

    std::cout << avl_tree.calcResult(avl_tree.root);
}
