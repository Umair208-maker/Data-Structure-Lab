#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string value) {
        category = value;
        left = NULL;
        right = NULL;
    }
};

void breadthFirstTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    cout << "BFS order: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->category << " ";

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
    cout << endl;
}

int main() {
    // Create a binary tree of seven shopping categories.
    Node* root = new Node("Electronics");
    root->left = new Node("Clothing");
    root->right = new Node("Mobiles");
    root->left->left = new Node("Laptops");
    root->left->right = new Node("Men");
    root->right->left = new Node("Women");
    root->right->right = new Node("Accessories");

    cout << "ONLINE SHOPPING CATEGORIES" << endl;
    breadthFirstTraversal(root);

    return 0;
}
