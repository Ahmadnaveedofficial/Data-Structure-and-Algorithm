#include <iostream>
using namespace std;

// Task 5: Function to double a value using pointer
void doubleValue(int*ptr){
    *ptr*=2;
}

// Task 6: Recursive factorial function
int factorial(int n) {
    if(n==0||n==1){
    	 return 1;
	}
       
    return n*factorial(n-1);
}

int main() {
    // Task 1: Array Initialization and Sum
    int arr[5]={10, 20, 30, 40, 50};
    int sum=0;
    for(int i=0;i<5;i++) {
        sum+=arr[i];
    }
    cout<<"Task 1- Sum of array elements: "<<sum<<endl;

    // Task 2: Pointer Basics
    int num=42;
    int* ptr=&num;
    cout<<"Task 2 - Value: "<<num<<", Address: "<< &num<< ", Dereferenced: "<<*ptr<<endl;

    // Task 3: Simple 2D Array Traversal
    int matrix[3][3]={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout<<"Task 3 - 3x3 Matrix:"<<endl;
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    // Task 4: Dynamic Array Creation
    int N;
    cout<<"Task 4 - Enter size of dynamic array: ";
    cin>>N;
    int* dynArr=new int[N];
    cout<<"Enter "<<N<<" integers:"<<endl;
    for(int i=0;i<N; i++){
        cin>>dynArr[i];
    }
    cout<<"You entered: ";
    for(int i=0;i<N;i++) {
        cout<<dynArr[i]<<" ";
    }
    cout<<endl;

    // Task 5: Using Pointers to Modify Data
    int value=10;
    doubleValue(&value);
    cout<<"Task 5 - Value after doubling: "<<value<<endl;

    // Task 6: Factorial using Recursion
    int factInput=5;
    cout<<"Task 6 - Factorial of "<<factInput<<" is: "<<factorial(factInput)<<endl;

    return 0;
}