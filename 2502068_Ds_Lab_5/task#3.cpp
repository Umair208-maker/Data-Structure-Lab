#include <iostream>
using namespace std;

class Node
{
public:
    string player;
    Node* next;

    Node(string name)
    {
        player = name;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Player 1");
    Node* second = new Node("Player 2");
    Node* third = new Node("Player 3");
    Node* fourth = new Node("Player 4");
    Node* fifth = new Node("Player 5");

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    
    fifth->next = first;

    Node* current = first;

    cout << "Game Player Turns:" << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << current->player << endl;
        current = current->next;
    }

    cout << "\nAfter the last player, turn returns to: ";
    cout << current->player << endl;

    return 0;
}
