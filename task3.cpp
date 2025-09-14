/*Task 3:
Create an array of integers with a size of 5.
Use a loop to fill the array with consecutive even numbers starting from 2.
Create a pointer that points to the first element of the array.
Use a loop to print the elements of the array using the pointer.*/
#include<iostream>
using namespace std;
int main(){
    int array[5];
    cout<<"enter the element of array: ";
    for (int  i=0;i<5; i++)
    {
        cin>>array[i];
    }

    int *ptr=array;
    for (int i=0;i<5;i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    

    
}

