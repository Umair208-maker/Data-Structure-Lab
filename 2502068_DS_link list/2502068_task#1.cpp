#include<iostream>
using namespace std;

class Node{
	public:
	    int student_Roll_no;
     	Node* next;
};

int main(){
	
	Node* head=new Node();
	Node* second=new Node();
	Node* third=new Node();
	
	head->student_Roll_no=25001;
	second->student_Roll_no=25002;
	third->student_Roll_no=25003;
	
	head->next=second;
	second->next=third;
	third->next = NULL;
	
	Node* new_student=new Node();
	new_student->student_Roll_no=25004;
	new_student->next=NULL;
	
	Node* current=head;
	while(current!=NULL){
		cout<<current->student_Roll_no<<endl;
		current=current->next;
	}
	third->next = new_student;
	
	current = head;
	while(current!=NULL){
		cout<<current->student_Roll_no<<endl;
		current=current->next;
	}
	
	
	int a;
	cout<<"Enter roll no to search";
	cin>>a;
	
	bool found=false;
	
	current = head;
	while(current!=NULL){
		
		if(current->student_Roll_no==a){
			found=true;
			break;
		}
		else{ 
		    
		    current=current->next;
		}
		
	}
	
	if(found){
		cout<<a<<" Found in link list";
	}
	else {
		cout<<a<<" Not found in link list";
	}
	
	return 0;
}
