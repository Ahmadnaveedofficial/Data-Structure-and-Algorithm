// write a C++ program to do the following tasks using 2d dynamic memory allocation:
// 1) write a dynamic 2d array of m*n elements, input value and display it
// 2) find the transpose of a matrix
// 3) find the sum of diagonal elements (dynamic allocation of a square matrix)

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout<<"Enter number of rows (m): ";
    cin>>m;
    cout<<"Enter number of columns (n): ";
    cin>>n;

    // Dynamic allocation of 2D array
    int** arr = new int*[m];
    for(int i=0;i<m; i++) {
        arr[i]=new int[n];
    }

    cout << "Enter elements of the matrix:" << endl;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<"Matrix:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Transpose of the matrix:"<<endl;
    for(int j=0;j<n;j++) {
        for(int i=0;i<m;i++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    if(m==n) {
        int diagSum = 0;
        for(int i=0;i<n;i++) {
            diagSum+=arr[i][i];
        }
        cout<<"Sum of diagonal elements: "<<diagSum<<endl;
    } else {
        cout<<"Diagonal sum only for square matrix."<<endl;
    }

    return 0;
}






