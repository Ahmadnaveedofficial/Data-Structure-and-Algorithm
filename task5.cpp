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