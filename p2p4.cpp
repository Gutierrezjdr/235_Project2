/*
Name:Jessica Gutierrez
Date:05/02/2018
Class:CSCI 235 -Software Analysis 2
Desc: This program takes two numbers represented by a linked list, where each node contains a single digit.The digits
are stored in reverse order, such that the 1 's digit is at the head of the list. The ADD function adds them together 
and outputs the sum as a linked list. 

*/


#include<iostream>

using namespace std;

struct node{
	int data;
	node* next;
	
};

node* Convert(int in);
node* Add(node* one,node* two);
void Print(node * head);


int main(){
	//Integers for addend
	int first;
	int second;
	
	//Nodes for addends and sum
	node *one;
	node *two;
	node *sum;
	
	cout<<"Please enter the first number to add: ";
	cin>>first;
	one=Convert(first);			//linked list conversion of decimal
	Print(one);					//Prints linked list
	
	cout<<"Please enter the second number to add: ";
	cin>>second;
	two=Convert(second);		//linked list conversion of decimal
	Print(two);					//Prints linked list

	
	sum = Add(one,two);			//linked list of sums
	Print(sum);					//Prints linked list


}

//Converts decimal number to linked list. 
node *Convert(int in){
	
	node * head=new node;		
	node * current;
	current= head;
	int rem;					//remainder

	while(current!=NULL){		//while list is not NULL
		rem=in%10;				//remainder of integer
		in=in/10;				//quotient of integer
			
			if(rem>0){			//if the remainder is more than 0
			 current->data=rem; //push remainder into list
			 current->next=new node;	//create new node.
			 current=current->next;		//go to next node
			}else{
			 current=NULL;		//make node NULL
			}
				 
	}
		
	return head;				//returns start of node.  	
}

//Adds numbers stored in a linked list and stores the sum into another.
node* Add(node *s1,node*s2){ 

	node *sum=new node;	//new list for the sum
	node *sumHead=sum;	//head of sum linked list
	
	node *temp1=s1;		//addend 1
	node *temp2=s2;		//addend 2
	
	int total;			//stores total
	int carryOut=0;		//stores carryout
	
	while(temp1->next!=NULL&&temp2->next!=NULL){	//while the next nodes are not NULL
		
		if(temp1->next!=NULL&&temp2->next!=NULL){	//if they are both not NULL
			total = (temp1->data)+(temp2->data)+carryOut;	//total is the sum of both digits and
															//the carryout from the sum of the previous positions			
			if(total<10){			//if the total is less than ten
				sum->data=total;	//push straight to node since there is no carryout
					
			}else {					//if total is more than or equal to 10
				carryOut=total/10;	//carry out is the quotient pf the total and 10
				sum->data=total%10;	//push remainder into sum node	
			}
		}else if (temp1==NULL&&temp2!=NULL){	//if temp1 has no digit but temp2 does
			sum->data=temp2->data;				//push temp2 digit to sum
		}else if (temp2==NULL&&temp1!=NULL){	//if temp2 has no digit but temp1 does
			sum->data=temp1->data;				//push temp1 digit to sum
		}
		//cout<<" Sum: "<<sum->data<<endl;		//for debugging
	
		if(temp1->next!=NULL) temp1=temp1->next;	//if next not is not Null go to next
		if(temp2->next!=NULL)temp2=temp2->next;
		sum->next=new node;						//make a new node in the sum linked list
		sum=sum->next;							//go to next node
				
	}
	 if(total>10){								//if the last total is more than 10
		sum->data=total/10;						//push
		cout<<" Sum: "<<sum->data<<endl;	
	 }
	return sumHead;
		
}



void Print(node *head){
	node *temp=head;
	while(temp!=NULL){
		
		cout<<temp->data;
		if(temp->next!=NULL) {		
		    
			cout<<" -> ";
		}else{
			cout<<"\n";
		}
		temp=temp->next;
		
		
		
		
	}
	
	
	
}


