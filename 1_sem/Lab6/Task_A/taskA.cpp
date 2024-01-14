#include <iostream>
#include <vector>

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

struct AVLTree {
    int calcHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return node->height;
        }
    }

    void updateFuckingHeightForReducingFuckingTimeLimitOn223Test(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        int height_of_left_subtree = calcHeight(node->left);
        int height_of_right_subtree = calcHeight(node->right);

        int current_height = std::max(height_of_left_subtree, height_of_right_subtree) + 1;
        node->height = current_height;
    }

    int calcBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return calcHeight(node->right) - calcHeight(node->left);
        }
    }

    void buildTree(std::vector<Node*> &nodes, int i, int key, int right_index, int left_index) {
        nodes[i]->key = key;

        if (left_index != 0) {
            nodes[i]->left = nodes[left_index - 1];
        } else {
            nodes[i]->left = nullptr;
        }

        if (right_index != 0) {
            nodes[i]->right = nodes[right_index - 1];
        } else {
            nodes[i]->right = nullptr;
        }

        updateFuckingHeightForReducingFuckingTimeLimitOn223Test(nodes[i]);
    }
};

int main() {
    int n;
    std::cin >> n;

    AVLTree avl;
    std::vector<Node*> nodes(n);

    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node();
        nodes[i]->key = 0;
        nodes[i]->height = 1;
        nodes[i]->left = nullptr;
        nodes[i]->right = nullptr;
    }

    for (int i = 0; i < n; i++) {
        int k, l, r;
        std::cin >> k >> l >> r;
        avl.buildTree(nodes, i, k, r, l);
    }

    for (int i = n - 1; i >= 0; i--) {
        avl.updateFuckingHeightForReducingFuckingTimeLimitOn223Test(nodes[i]);
    }

    for (int i = 0; i < n; i++) {
        std::cout << avl.calcBalanceFactor(nodes[i]) << "\n";
    }
}