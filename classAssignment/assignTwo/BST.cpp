#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert into BST
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Find minimum value
    int findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node->data;
    }

    // Find maximum value
    int findMax(Node* node) {
        while (node->right != nullptr)
            node = node->right;
        return node->data;
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;

    int values[] = {20, 12, 25, 7, 15, 22, 30};
    int n = sizeof(values) / sizeof(values[0]);

    // i) Create BST
    for (int i = 0; i < n; i++) {
        tree.root = tree.insert(tree.root, values[i]);
    }

    cout << "Binary Search Tree (In-order Traversal): ";
    tree.inorder(tree.root);
    cout << endl;

    // ii) Minimum fuel consumption
    cout << "Minimum fuel consumption route: " 
         << tree.findMin(tree.root) << endl;

    // iii) Maximum fuel consumption
    cout << "Maximum fuel consumption route: " 
         << tree.findMax(tree.root) << endl;

    return 0;
}
