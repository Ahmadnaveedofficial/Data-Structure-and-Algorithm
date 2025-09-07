//  write a C++ program to do the following tasks using dynamic memory allocation:
//  1) write a dymamic 1d array of n elements ,input value and display it
// 2) find the largest or smallest element in the array
//  3) write the reverse of a dynamic allocated array
//  4) count how many even and odd number in dynamic allocated array

#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array elements are:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int largest=arr[0];
    for (int i=1;i<n;i++) {
        if(arr[i]>largest) {
            largest=arr[i];
        }
    }

    // Find smallest
    int smallest = arr[0];
    for(int i=1;i<n;i++) {
        if (arr[i]<smallest) {
            smallest=arr[i];
        }
    }

    cout<<"Largest element: "<<largest<<endl;
    cout<<"Smallest element: "<<smallest<<endl;

    // Reverse array
    cout<<"Reversed array elements are:"<<endl;
    for(int i=n-1;i>=0;i--) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Count even and odd
    int evenCount=0,oddCount = 0;
    for(int i=0; i < n; i++){
        if(arr[i]%2==0){
            evenCount++;
        }else {
            oddCount++;
        }
    }
    cout<<"Number of even elements: "<<evenCount<<endl;
    cout<<"Number of odd elements: "<<oddCount<<endl;
    return 0;
}



// write a C++ program to do the following tasks using dynamic memory allocation:
// 1) implement a function that  return  the largest element in a dynamic allocation array using pointer


// #include <iostream>
// using namespace std;

// int findLargest(int* arr, int n) {
//     int largest = arr[0];
//     for(int i=1;i<n;i++) {
//         if(arr[i]>largest) {
//             largest=arr[i];
//         }
//     }
//     return largest;
// }

// int main() {
//     int n;
//     cout<<"Enter the number of elements in the array: ";
//     cin>>n;
//     int* arr=new int[n];
//     cout<<"Enter "<<n<<" elements:"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int largest = findLargest(arr,n);
//     cout<<"Largest element is: "<<largest<<endl;
//     delete[] arr;
//     return 0;
// }

// 2) create a simple student database (name,roll,marks) using structure and dynamic memory allocation
// #include <iostream>
// #include <string>
// using namespace std;
// struct Student {
//     string name;
//     int roll;
//     float marks;
// };
// int main() {
//     int n;
//     cout<<"Enter the number of students: ";
//     cin>>n;
//     Student* students = new Student[n];
//     for(int i=0;i<n;i++) {
//         cout<<"Enter details for student "<<i+1<<":"<<endl;
//         cout<<"Name: ";
//         cin>>students[i].name;
//         cout<<"Roll: ";
//         cin>>students[i].roll;
//         cout<<"Marks: ";
//         cin>>students[i].marks;
//     }
//     cout<<"Student Database:"<<endl;
//     for(int i=0;i<n;i++) {
//         cout<<"Student "<<i+1<<":"<<endl;
//         cout<<"Name: "<<students[i].name<<endl;
//         cout<<"Roll: "<<students[i].roll<<endl;
//         cout<<"Marks: "<<students[i].marks<<endl;
//     }
//     return 0;
// }


