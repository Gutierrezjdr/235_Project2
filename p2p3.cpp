/*
Name:Jessica Gutierrez
Date:04/26/2018
Class:CSCI 235 -Software Analysis 2
Desc: This program takes a circular linked list from the user 
and outputs the node in which the circular linked list starts.

*/


#include<iostream>

using namespace std;

int main(){
	string input;
	string temp;
	string store[10];
	cout<<"Input circular linked list. (Ex. A->B->C): ";
	cin>>input;
	
	cout<<input<<endl;
	struct Data{
			char data;
			Data* next;
	};
	int j=0;
	for(int i=0;i<(input.length());i++){
	  if(input[i]!='>'&&input[i]!='-'){
		temp+=input[i];
			if(input[i+1]=='-'|| i+1==input.length()){
				store[j]=temp;
				//cout<<" J: "<<j<<" Word "<<store[j]<<endl;
				temp="";
				j++;
	  
				
				
			}
		
		  
	  }else{
		
	  }

		
	}



}
