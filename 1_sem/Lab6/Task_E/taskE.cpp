#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string key;
    int height;
    Node* left;
    Node* right;

    Node(std::string filename) : key(filename), height(1), left(nullptr), right(nullptr) {}
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

    Node* insert(Node* node, std::string filename) {
        if (node == nullptr) {
            return new Node(filename);
        }

        if (filename < node->key) {
            node->left = insert(node->left, filename);
        } else if (filename > node->key) {
            node->right = insert(node->right, filename);
        }

        node = balanceNode(node);

        return node;
    }

    bool search_file_node(Node* node, std::string filename) {
        if (node == nullptr) {
            return false;
        }

        if (filename == node->key) {
            return true;
        } else if (filename < node->key) {
            return search_file_node(node->left, filename);
        } else if (filename > node->key) {
            return search_file_node(node->right, filename);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<std::string>> filenames_per_all_students(3);
    std::vector<AVLTree> avl_trees(3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::string filenames;
            std::cin >> filenames;

            filenames_per_all_students[i].push_back(filenames);
            avl_trees[i].root = avl_trees[i].insert(avl_trees[i].root, filenames_per_all_students[i][j]);
            avl_trees[i].root = avl_trees[i].balanceNode(avl_trees[i].root);
        }
    }

    std::vector<int> scores_per_students(3, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int cheating_students = 0;
            for (int l = 0; l < 3; l++) {
                if (j != l) {
                    if (avl_trees[l].search_file_node(avl_trees[l].root, filenames_per_all_students[j][i])) {
                        cheating_students++;
                    }
                }
            }

            if (cheating_students == 0) {
                scores_per_students[j] += 3;
            }
            else if (cheating_students == 1){
                scores_per_students[j] += 1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        std::cout << scores_per_students[i] << " ";
    }
}