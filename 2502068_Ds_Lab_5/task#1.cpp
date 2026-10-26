#include <iostream>
using namespace std;

class Node
{
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name)
    {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Google");
    Node* second = new Node("YouTube");
    Node* third = new Node("GitHub");
    Node* fourth = new Node("Facebook");
    Node* fifth = new Node("Wikipedia");

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    Node* last = fifth;

    cout << "Browser History (First -> Last):" << endl;

    Node* current = first;

    while (current != NULL)
    {
        cout << current->website << endl;
        current = current->next;
    }

    cout << "\nBrowser History (Last -> First):" << endl;

    current = last;

    while (current != NULL)
    {
        cout << current->website << endl;
        current = current->prev;
    }

    return 0;
}
