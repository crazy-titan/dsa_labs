#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // 🔹 Insert a new node
    Node* insert(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    // 🔹 Search for a value
    bool search(Node* node, int key) {
        if (node == NULL)
            return false;

        if (key == node->data)
            return true;
        else if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 🔹 Find minimum node (used in deletion)
    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    // 🔹 Delete a node
    Node* deleteNode(Node* node, int key) {
        if (node == NULL)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // Node found
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with 2 children: get inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // 🔹 Inorder traversal (Left → Root → Right)
    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;

    // Insert elements
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder traversal of BST: ";
    tree.inorder(tree.root);
    cout << endl;

    // Search operation
    int key = 40;
    if (tree.search(tree.root, key))
        cout << key << " found in BST." << endl;
    else
        cout << key << " not found in BST." << endl;

    // Delete operation
    cout << "Deleting 20..." << endl;
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "Inorder after deleting 20: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Deleting 30..." << endl;
    tree.root = tree.deleteNode(tree.root, 30);
    cout << "Inorder after deleting 30: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Deleting 50..." << endl;
    tree.root = tree.deleteNode(tree.root, 50);
    cout << "Inorder after deleting 50: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
