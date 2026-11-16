#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        token = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalanceFactor(Node* node) {
    return (node == NULL) ? 0
        : getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left),
                           getHeight(node->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* middle = x->right;

    x->right = y;
    y->left = middle;

    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* middle = y->left;

    y->left = x;
    x->right = middle;

    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, int value) {
    // 1. Insert using normal BST rules.
    if (node == NULL)
        return new Node(value);

    if (value < node->token)
        node->left = insert(node->left, value);
    else if (value > node->token)
        node->right = insert(node->right, value);
    else
        return node; // Do not insert duplicate tokens.

    // 2. Update height and calculate balance factor.
    updateHeight(node);
    int balance = getBalanceFactor(node);

    // 3. Handle all four AVL imbalance cases.

    // LL case
    if (balance > 1 && value < node->left->token)
        return rightRotate(node);

    // RR case
    if (balance < -1 && value > node->right->token)
        return leftRotate(node);

    // LR case
    if (balance > 1 && value > node->left->token) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL case
    if (balance < -1 && value < node->right->token) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->token << " ";
    inOrder(root->right);
}

void displayTree(Node* root, string indent = "", bool isLeft = true) {
    if (root == NULL) return;

    cout << indent;
    cout << (isLeft ? "|-- " : "\\-- ");
    cout << root->token
         << " (height=" << root->height
         << ", BF=" << getBalanceFactor(root) << ")" << endl;

    string nextIndent = indent + (isLeft ? "|   " : "    ");
    displayTree(root->left, nextIndent, true);
    displayTree(root->right, nextIndent, false);
}

int main() {
    Node* root = NULL;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++)
{
    root = insert(root, tokens[i]);
}

    cout << "HOSPITAL APPOINTMENT AVL TREE" << endl;
    cout << "Inserted tokens: 15 25 35 45 55 65 75" << endl;

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl << endl;

    cout << "Final balanced tree (height and balance factor):" << endl;
    displayTree(root, "", false);

    return 0;
}
