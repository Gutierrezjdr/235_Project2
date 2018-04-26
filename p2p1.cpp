/*
Name: Jessica Gutierrez
Date: 4/24/2018
Class: CSCI 235: Software Analysis
Desc: This program takes a list of unordered numbers and transfers it into a stack. Using only one extra stack and no other data structures this program 
orders the numbers and places the lowest value on top of the stack. 

*/


#include<iostream>
#include<stack>
#include<string>

using namespace std;
void Swap(stack<int> *s, stack<int> *s2);	//used to swap stacks
void Print(stack<int> *s);	//Used to print stack
void Order(stack<int> *s,stack<int> *s2,int temp); //Used to order numbers
int main(){
	string input;
	stack<int> s1;
	stack<int> s2;
	stack<int> *sPtr1=&s1;
	stack<int> *sPtr2=&s2;
	cout<<"Please type the numbers in order of position starting from the bottom of the stack.\n"<<"Seperate with commas: ";
	cin>>input;
//	cout<<input;
	string temp;
	int i=0;
	for(int i=0;i<=(input.length()-1);i++){
	  if(input[i]!=','){
		if(input[i+1]=='\0') {
	  	 temp+=input[i];
		 s1.push(stoi(temp));
		 
		}else{
	   	 temp+=input[i];
		}
 
	  }else{
	   s1.push(stoi(temp));
	   temp=" "; 
	  }
	
	}
	//Print(sPtr1);
	Swap(sPtr1,sPtr2);
	
}
void Swap(stack<int> *stackOut,stack<int> *stackIn){
	int max=0;
	int min=0;
	int temp=0;
	bool maxIn=false;
	bool minIn=false;

	while(!stackOut->empty()){

	    if(stackOut->top()>=max){
			
			if(maxIn){ //Runs after the first max has been found
			  temp=max;						//Stores previous Max
				if(temp<=min){ 				//checks if it is a minimum
				  min=temp;
				  minIn=true;
				}else if(stackIn->empty()){ //runs if stack is empty
				  stackIn->push(temp); 
				}else if(!stackIn->empty()&&temp<stackIn->top()){ //rearranges numbers if current one is less than the top of the temporary stack
				  Order(stackOut,stackIn,temp);
				}else{
				 stackIn->push(temp);
				}
			  max=stackOut->top();
			  stackOut->pop();
			}else{ 
			 maxIn=true;
			 max=stackOut->top();
			 min=max;
			 stackOut->pop();	
			}
//			cout<<"Max: "<<max<<" Temp: "<<temp<<endl;
		}else if(stackOut->top()<=min){ //Runs if the number is less than minimum
			
			if(minIn){	//runs if the first minimum has been found
			   temp=min;  	  
			 	if(stackIn->empty()){
			   	   stackIn->push(temp);
			        }else if(!stackIn->empty()&&temp<stackIn->top()){
				  Order(stackOut,stackIn,temp);
				}
			  min=stackOut->top();
			  stackOut->pop();	
			}else{
				min=stackOut->top();
				minIn=true;
				stackOut->pop();
			}

		  }else{	//Runs if number is neither a min or max
			 	
			temp=stackOut->top();
			
			//puts smallest number under those of higher value
			if(!stackIn->empty()&&temp<stackIn->top()){ 
				Order(stackOut,stackIn,temp);
			
			}else{	
			    stackIn->push(temp);
			}
			stackOut->pop();
		} 	
//		cout<<"Min: "<<min<<" Temp: "<<temp<<endl;
		
	}
	//Inserts ordered numbers back into original stack 
	stackOut->push(max);
	while(!stackIn->empty()){
	  stackOut->push(stackIn->top());
	  stackIn->pop();
	}
	 stackOut->push(min);
	 Print(stackOut);
	

}

void Order(stack<int> * stackOut,stack<int>* stackIn,int temp){
	
	int pushback=0;			//Stores number higher than temp that need to be pushed back
	//runs while the stoes number is less than the number inside the stack
	while(!stackIn->empty()&&temp<stackIn->top()){
		stackOut->push(stackIn->top());	//moves higher number to other stack
		stackIn->pop();					//removes number from original stack
		pushback++;						//counts by 1
	  
	  }
	  stackIn->push(temp);				//pushes small number into place
	  while(pushback>0){ 				//pushes back all the numbers more than temp
		stackIn->push(stackOut->top());
		stackOut->pop();
		pushback--;
	  }

	
	
	
	
}
// Prints stack. Used to debug but also does not
// replenish info back into stack so it is only used once
void Print(stack<int> *s){
	while(!s->empty()){
		cout<<s->top()<<endl;
		s->pop();
	}

}
