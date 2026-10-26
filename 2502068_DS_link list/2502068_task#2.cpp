#include <iostream>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;
};

int main() {

    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    
    head->patientID = "P101";
    second->patientID = "P102";
    third->patientID = "P103";
    fourth->patientID = "P104";

   
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    
    Node* current = head;

    cout << "Waiting Patients:" << endl;

    while (current != NULL) {
        cout << current->patientID;

        if (current->next != NULL) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;

    
    cout << "Patient " << head->patientID << " is being served." << endl;

    Node* temp = head;
    head = head->next;
    delete temp;

    
    cout << "Updated Queue:" << endl;

    current = head;

    while (current != NULL) {
        cout << current->patientID;

        if (current->next != NULL) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;

    return 0;
}
