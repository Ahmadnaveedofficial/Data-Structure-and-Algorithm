/*b) Write a function findMax(int arr[], int size) that takes an array and its size as parameters.
The function should find and return the largest element present in the array.
Example: If the array is {3, 9, 2, 11, 6}, the function should return 11.*/

#include <iostream>
using namespace std;
int findMax(int arr[],int size) {
    int max=arr[0];
    for (int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int arr[]={3, 9, 2, 11, 6};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Largest element in the array: "<<findMax(arr,size)<<endl;
    return 0;
}