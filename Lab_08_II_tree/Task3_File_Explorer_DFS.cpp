#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->folder << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->folder << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->folder << " ";
}

int main() {
    // Create a binary tree containing seven folders.
    Node* root = new Node("Computer");
    root->left = new Node("Documents");
    root->right = new Node("Pictures");
    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");
    root->right->left = new Node("Family");
    root->right->right = new Node("Travel");

    cout << "COMPUTER FILE EXPLORER - DFS TRAVERSALS" << endl;

    cout << "In-order (Left, Root, Right): ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order (Root, Left, Right): ";
    preOrder(root);
    cout << endl;

    cout << "Post-order (Left, Right, Root): ";
    postOrder(root);
    cout << endl;

    return 0;
}
