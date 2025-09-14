/*Task 2:
Create a program that dynamically allocates memory for an integer variable.
Ask the user to input an integer value.
Use dynamic memory allocation to allocate memory for an integer and store the user's input in it.
Print the value stored in the dynamically allocated integer.
Don’t forget to free the allocated memory to avoid memory leaks.
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

