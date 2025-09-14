/*Task 5:
Create a program that demonstrates the use of pointer to pointer (double pointer).
Declare a pointer to an integer variable.
Initialize a variable with an integer value.
Declare another pointer to a pointer and make it point to the address of the first pointer.
Print the value of the integer using both pointers.*/


#include<iostream>
using namespace std;
int main(){
    int var=42;
    int *ptr=&var;
    int **dptr=&ptr;
    cout<<"value of var "<<var<<endl;
    cout<<"value of ptr "<<*ptr<<endl;
    cout<<"value of dptr "<<**dptr<<endl;
}





/*Task 6:
Write a program that dynamically allocates memory for an integer array of user-defined size.
Ask the user to input the size of the array.
Allocate memory for the array and initialize its elements with random values.
Write a function to find the maximum and minimum values in the array and return them.*/