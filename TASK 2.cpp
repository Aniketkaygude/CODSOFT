#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*  Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform. */



int main(){

int num1=0;
int num2 =0;

cout<<"\nEnter Number 1 --> ";
cin>> num1;
cout<< endl<<endl;

cout<<"Enter Number 2 --> ";
cin>> num2;
cout<<endl<<endl;

int loop =0;

while(loop == 0){
	
	cout<<" You can perform following operations "<<endl<<endl;
	cout<<"\n\n1--> Addition"<<endl;
	cout<<"2--> Subtraction"<<endl;
	cout<<"3--> Multiplication"<<endl;
	cout<<"4--> Division"<<endl;
	cout<<"5--> Exit"<<endl<<endl;
	
	int choice=0;
	cout<<"Enter the choice --> ";
	cin>>choice;
	
	switch(choice){
	 
	 case 1: {
	 	cout<< "\nAddition of 2 Numbers --> "<<num1 + num2<<endl<<endl;
		break;
	 }
	 
	 case 2: {
	 	
		 int ans=num1>=num2?num1-num2:num2-num1;
		cout<< "\nSubtraction of 2 Numbers --> "<<ans<<endl<<endl;
		
	 }
	 
	 case 3: {
	 	cout<< "\nMultiplication of 2 Numbers --> "<<num1 * num2<<endl<<endl;
		break;
	 }
	 
	 case 4: {
	 	cout<< "\nDivision of 2 Numbers --> "<<num1 / num2<<endl<<endl;
		break;
	 }
	 
	 case 5: {
	 	loop++;
	 	cout<< "\n\n--------------Program Ended------------- "<<num1 / num2<<endl<<endl;
		break;
	 }
	 	
	}
}


	return 0 ;
}
