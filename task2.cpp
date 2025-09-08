/*
  create a program that a dynamic allocation for an 
*/









#include <iostream>
using namespace std;
int main(){
   int *n=new int ;
   cout<<"enter the integer: ";
   cin>>*n;
   cout<<*n;
   delete n;
}

