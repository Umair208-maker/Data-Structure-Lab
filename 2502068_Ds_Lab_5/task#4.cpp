#include <iostream>
using namespace std;

class Node
{
public:
    string song;
    Node* next;

    Node(string name)
    {
        song = name;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Song 1");
    Node* second = new Node("Song 2");
    Node* third = new Node("Song 3");
    Node* fourth = new Node("Song 4");
    Node* fifth = new Node("Song 5");

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    
    fifth->next = first;

    Node* current = first;

    cout << "Music Playlist (Once):" << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << current->song << endl;
        current = current->next;
    }

    cout << "\nPlaying Playlist for 2 Complete Rounds:" << endl;

    current = first;

    for (int i = 1; i <= 10; i++)
    {
        cout << current->song << endl;
        current = current->next;
    }

    return 0;
}
