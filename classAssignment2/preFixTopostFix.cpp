#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


class Node {
public:
    string data;
    Node *left, *right;

    // Constructor
    Node(string val) {
        data = val;
        left = right = NULL;
    }
};


Node* buildTree(vector<string>& tokens, int& index) {

    // Stop if index is outside vector
    if (index >= tokens.size())
        return NULL;

    // Read current token
    string token = tokens[index];

    // Create a new node
    Node* node = new Node(token);

    // If operator → build left & right subtrees
    if (token == "+" || token == "-" || token == "*" || token == "/") {

        index++;  // Move to next token
        node->left = buildTree(tokens, index);

        index++;  // Move to next token
        node->right = buildTree(tokens, index);
    }

    // If operand → return leaf node
    return node;
}


void postorder(Node* root) {
    if (!root) return;

    postorder(root->left);   // Left subtree
    postorder(root->right);  // Right subtree
    cout << root->data << " ";
}


int main() {

    string input = "* a + b * c + d e";  // prefix expression
    stringstream ss(input);

    vector<string> tokens;
    string token;

    // Split prefix expression into tokens
    while (ss >> token)
        tokens.push_back(token);

    int index = 0;

    // Build the tree
    Node* root = buildTree(tokens, index);

    // Print postfix
    cout << "Postfix expression: ";
    postorder(root);

    return 0;
}
