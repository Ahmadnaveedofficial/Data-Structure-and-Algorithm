// quick sort

#include <iostream>
using namespace std;

int partition(int array[],int low,int high) {
    int pivot=array[high];// pivot
    int i=low-1; // Index of smaller element

    for(int j=low;j<high;j++){
        if (array[j]<pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1],array[high]);
    return i + 1;
}

void quickSort(int array[],int low,int high){
    if(low<high){
        int pi=partition(array,low,high);

        quickSort(array,low,pi-1);
        quickSort(array,pi+1,high);
    }
}
void printarray(int array[],int n){
    for (int i = 0; i < n; i++)
        {
            cout<<array[i]<<" ";
        }
}
int main() {
    int n;
    cout<<"Enter the number of element: ";
    cin>>n;
    int array[n];
    cout<<"Enter the "<<n<<" element : ";
    for(int i=0;i<n;i++){
       cin>>array[i];
    }
    cout<<"The element of array is : ";
    printarray(array,n);
    cout<<endl;
    quickSort(array, 0, n - 1);
    cout<<"Sorted array: ";
    printarray(array,n);
    return 0;
}
