#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node class for general tree
class Node {
public:
    string data;
    vector<Node*> children;   // A node may have multiple children

    Node(string value) {
        data = value;
    }
};

// Function to print tree level-wise (BFS)
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "Level-wise traversal: ";

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        // push all children into queue
        for (Node* child : curr->children)
            q.push(child);
    }
    cout << endl;
}

// Function to print leaf nodes (delivery end points)
void printLeafNodes(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "Leaf/End delivery points: ";

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Leaf node → no children
        if (curr->children.size() == 0)
            cout << curr->data << " ";

        for (Node* child : curr->children)
            q.push(child);
    }
    cout << endl;
}

int main() {
    // Manually build the tree from diagram

    Node* zone = new Node("Zone-1");

    Node* cityA = new Node("City-A");
    Node* cityB = new Node("City-B");
    Node* cityC = new Node("City-C");

    zone->children = {cityA, cityB, cityC};

    // Children of City-A
    Node* A1 = new Node("A1");
    Node* A2 = new Node("A2");
    cityA->children = {A1, A2};

    // Children of City-B
    Node* B1 = new Node("B1");
    cityB->children = {B1};

    // Children of City-C
    Node* C1 = new Node("C1");
    cityC->children = {C1};

    // Print level-wise
    levelOrder(zone);

    // Print leaf nodes
    printLeafNodes(zone);

    return 0;
}
