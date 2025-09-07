/*a) Write a function sumArray(int arr[], int size) that takes an array and its size as parameters.
The function should calculate and return the sum of all elements in the array.
Example: If the array is {2, 5, 7}, the function should return 14.*/

#include <iostream>
using namespace std;
int sumArray(int arr[], int size) {
    int sum=0;
    for (int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
int main() {
    int arr[]={2, 5, 7};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum of array elements: "<<sumArray(arr,size)<<endl;
    return 0;
}