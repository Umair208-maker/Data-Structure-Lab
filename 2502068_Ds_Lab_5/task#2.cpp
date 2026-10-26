#include <iostream>
using namespace std;

class Node
{
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name)
    {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Image1.jpg");
    Node* second = new Node("Image2.jpg");
    Node* third = new Node("Image3.jpg");
    Node* fourth = new Node("Image4.jpg");
    Node* fifth = new Node("Image5.jpg");

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    Node* last = fifth;

    cout << "Image Gallery (First -> Last):" << endl;

    Node* current = first;

    while (current != NULL)
    {
        cout << current->image << endl;
        current = current->next;
    }

    cout << "\nImage Gallery (Last -> First):" << endl;

    current = last;

    while (current != NULL)
    {
        cout << current->image << endl;
        current = current->prev;
    }

    return 0;
}
