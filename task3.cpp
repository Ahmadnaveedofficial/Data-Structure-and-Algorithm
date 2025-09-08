/*create a array of integer with the size of 5
use a loop to fill the array of element with the consective even number starting from 2
create a pointer that point the first elemt of array 
use a loop to print the element of array using pointer*/
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

