#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string memberName) {
        name = memberName;
        left = NULL;
        right = NULL;
    }
};

void displayHierarchy(Node* root) {
    if (root == NULL) return;

    cout << "Member: " << root->name << endl;
    cout << "  Left child: "
         << (root->left ? root->left->name : "None") << endl;
    cout << "  Right child: "
         << (root->right ? root->right->name : "None") << endl << endl;

    displayHierarchy(root->left);
    displayHierarchy(root->right);
}

int main() {
    // Create seven department members.
    Node* hod = new Node("Dr. Ahmed (HOD)");
    hod->left = new Node("Dr. Sana (CS Coordinator)");
    hod->right = new Node("Dr. Bilal (SE Coordinator)");

    hod->left->left = new Node("Ali (CS Faculty)");
    hod->left->right = new Node("Ayesha (CS Faculty)");
    hod->right->left = new Node("Usman (SE Faculty)");
    hod->right->right = new Node("Hira (SE Faculty)");

    cout << "UNIVERSITY DEPARTMENT HIERARCHY" << endl << endl;
    displayHierarchy(hod);

    return 0;
}
