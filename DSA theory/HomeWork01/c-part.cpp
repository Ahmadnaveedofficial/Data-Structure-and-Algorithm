// c) Write a function swapNumbers(int &a, int &b) that swaps the values of two numbers using
// pass by reference. This way, the changes will reflect in the main function without
// returning values.
// Example: If a = 5 and b = 10, after calling swapNumbers(a, b), a = 10 and b = 5.

#include <iostream>
using namespace std;
void swapNumbers(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a, b;
    cout<<"Enter a ";
    cin>>a;
    cout<<"Enter b ";
    cin>>b;
    cout<<"Before swapping: a = "<<a<<", b = "<<b<<endl;
    swapNumbers(a,b);
    cout<<"After swapping: a = "<<a<<", b = "<<b<<endl;
    return 0;
}