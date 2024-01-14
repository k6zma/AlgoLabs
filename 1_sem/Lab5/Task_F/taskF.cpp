#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root = nullptr;

    Node* buildTreeFromPreorder(std::vector<int>& preorder_traversal_data, int min, int max, int& index) {
        if (index >= preorder_traversal_data.size()) {
            return nullptr;
        }

        if (preorder_traversal_data[index] < min || preorder_traversal_data[index] >= max) {
            return nullptr;
        }

        Node* node = new Node(preorder_traversal_data[index]);

        index++;

        node->left = buildTreeFromPreorder(preorder_traversal_data, min, node->key, index);
        node->right = buildTreeFromPreorder(preorder_traversal_data, node->key, max, index);

        return node;
    }

    void inorderTraversal(Node* node, std::vector<int>& result) {
        if (node != nullptr) {
            inorderTraversal(node->left, result);
            result.push_back(node->key);
            inorderTraversal(node->right, result);
        }
    }

    void postorderTraversal(Node* node, std::vector<int>& result) {
        if (node != nullptr) {
            postorderTraversal(node->left, result);
            postorderTraversal(node->right, result);
            result.push_back(node->key);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> slavas_preorder, slavas_inorder, slavas_postorder;

    for (int i = 0; i < n; ++i) {
        int key;
        std::cin >> key;
        slavas_preorder.push_back(key);
    }

    for (int i = 0; i < n; ++i) {
        int key;
        std::cin >> key;
        slavas_inorder.push_back(key);
    }

    for (int i = 0; i < n; ++i) {
        int key;
        std::cin >> key;
        slavas_postorder.push_back(key);
    }

    Tree tree;

    bool result_inorder = false;
    bool result_postorder = false;

    int temp_index = 0;
    tree.root = tree.buildTreeFromPreorder(slavas_preorder, -10000000000, 1000000001, temp_index);

    std::vector<int> check_inorder;
    std::vector<int> check_postorder;

    tree.inorderTraversal(tree.root, check_inorder);
    tree.postorderTraversal(tree.root, check_postorder);

    if (check_inorder == slavas_inorder) {
        result_inorder = true;
    }

    if (check_postorder == slavas_postorder) {
        result_postorder = true;
    }

    if (result_inorder && result_postorder) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
