#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string key;
    Node* left;
    Node* right;

    Node(std::string filename) : key(filename), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root = nullptr;

    Node* insert(Node* node, std::string filename) {
        if (node == nullptr) {
            return new Node(filename);
        }

        if (filename < node->key) {
            node->left = insert(node->left, filename);
        } else if (filename > node->key) {
            node->right = insert(node->right, filename);
        }

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
    std::vector<Tree> trees(3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::string filenames;
            std::cin >> filenames;

            filenames_per_all_students[i].push_back(filenames);
            trees[i].root = trees[i].insert(trees[i].root, filenames_per_all_students[i][j]);
        }
    }

    std::vector<int> scores_per_students(3, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int cheating_students = 0;
            for (int l = 0; l < 3; l++) {
                if (j != l) {
                    if (trees[l].search_file_node(trees[l].root, filenames_per_all_students[j][i])) {
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