#include <iostream>
#include <vector>
#include <string>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root = nullptr;

    Node* insert(Node* node, int key) {
        if (node == nullptr) {

            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        return node;
    }

    Node* min(Node* x) {
        if (x->left == nullptr) {
            return x;
        }

        return min(x->left);
    }

    Node* del(Node* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = del(node->left, key);
        } else if (key > node->key) {
            node->right = del(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                return temp;
            }

            Node* temp = min(node->right);

            node->key = temp->key;
            node->right = del(node->right, temp->key);
        }

        return node;
    }

    Node* merge(Node* node1, Node* node2) {
        if (node2 == nullptr) {
            return node1;
        }

        node1 = insert(node1, node2->key);
        node2 = del(node2, node2->key);

        return merge(node1, node2);
    }

    void inorderTraversal(Node* node, std::vector<int>& temp_vector) {
        if (node != nullptr) {
            inorderTraversal(node->left, temp_vector);
            temp_vector.push_back(node->key);
            inorderTraversal(node->right, temp_vector);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    Tree p2p_acc_first;
    Tree p2p_acc_second;

    for (int i = 0; i < n; ++i) {
        std::string command;
        int account, id;
        std::cin >> command;

        if (command == "buy") {
            std::cin >> account >> id;

            if (account == 1) {
                p2p_acc_first.root = p2p_acc_first.insert(p2p_acc_first.root, id);
            } else if (account == 2) {
                p2p_acc_second.root = p2p_acc_second.insert(p2p_acc_second.root, id);
            }

        } else if (command == "sell") {
            std::cin >> account >> id;

            if (account == 1) {
                p2p_acc_first.root = p2p_acc_first.del(p2p_acc_first.root, id);
            } else if (account == 2) {
                p2p_acc_second.root = p2p_acc_second.del(p2p_acc_second.root, id);
            }

        } else if (command == "merge") {
            std::vector<int> temp_vector_for_result;
            p2p_acc_first.root = p2p_acc_first.merge(p2p_acc_first.root, p2p_acc_second.root);
            p2p_acc_second.root = nullptr;
            if (p2p_acc_first.root != nullptr) {
                p2p_acc_first.inorderTraversal(p2p_acc_first.root, temp_vector_for_result);

                for (int j = 0; j < temp_vector_for_result.size(); j++) {
                    if (j == temp_vector_for_result.size() - 1) {
                        std::cout << temp_vector_for_result[j] << "\n";
                    } else {
                        std::cout << temp_vector_for_result[j] << " ";
                    }
                }
            }
        }
    }
}
