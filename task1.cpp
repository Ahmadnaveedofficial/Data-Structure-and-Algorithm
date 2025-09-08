/*
task 1
create an integer variable num ans set its value to 42
create a pointer varibale ptr that points to the address of num
print the value of num and the value pointed by the ptr
*/

#include <iostream>
using namespace std;
int main(){
    int num=42;
    int *ptr;
     *ptr=num;
    cout<<num<<endl;
    cout<<&ptr<<endl;
}