/*
Name:Jessica Gutierrez
Date:04/26/2018
Class:CSCI 235 -Software Analysis 2
Desc: This program takes a circular linked list created in a function
and outputs the node in which the circular linked list starts.

*/


#include<iostream>

using namespace std;

struct Node{
			char data;
			Node* next;
			bool nodeBool;
	};

void Create (Node *head);
void Print(Node *head);
Node Find(Node *head);
int main(){
	string input;
	Node *head = new Node;
	cout<<"Write 'print' to print the corrupted linked list. Else write 'origin' to print start of cycle in linked list. ";
	cin>>input;
	Create(head);
	if (input=="print")
	Print(head);
	else if (input=="origin")
	Find(head);	
	else
	cout<<"Wrong Input.";




}

void Create(Node *head){
	Node *current;
	Node *start;
	current =head;
	current->data='A';
	current->next=new Node;
	current->nodeBool=false;
	current=current->next;
	
	current->data='B';
	current->next=new Node;
	current->nodeBool=false;
	current=current->next;
	
	current->data='C';
	current->next=new Node;
	current->nodeBool=false;
	start=current;
	current=current->next;
	
	current->data='D';
	current->nodeBool=false;
	current->next=new Node;
	current=current->next;
	
	current->data='E';
	current->nodeBool=false;
	current->next=start;
	current=start;
	//current->next=NULL;
	//current=current->next;
	//current->data='C';
	//current= head;

	
	
	
	
	
	
}
Node Find(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		
		
		if(temp->nodeBool==false){
			temp->nodeBool=true;
			temp=temp->next;
		}else if (temp->nodeBool==true){
			cout<<temp->data<<endl;
			break;
		}
		
		
		
		
		
		
	}
	
	
	
	
	
}
void Print(Node *head){
	
		Node *temp=head;
	while(temp!=NULL){
		
		cout<<temp->data<<" -> ";
		temp=temp->next;
		
		
		
		
	}
	
	
	
	
}
