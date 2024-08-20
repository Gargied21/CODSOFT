#include<iostream>
using namespace std;

int sum(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}

int mult(int a,int b){
    return a*b;
}

int divi(int a,int b){
    return a/b;
}

int main(){
    int a,b;
    char c;
cout<<"Enter number1:";
cin>>a;
cout<<"Enter number2:";
cin>>b;
cout<<"Enter operator :";
cin>>c;
switch (c)
{
case '+': cout<<"Sum is :"<<sum(a,b)<<endl;    
    break;
case '-': cout<<"Subtraction is :"<<sub(a,b)<<endl; 
    break;

case '*': cout<<"multiplication is :"<<mult(a,b)<<endl; 
    break;

case '/': cout<<"division is :"<<divi(a,b)<<endl;  
    break;


default:cout<<"enter a valid input";
    break;
}
}

