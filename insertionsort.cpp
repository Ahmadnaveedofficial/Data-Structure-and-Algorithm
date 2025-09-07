// insertion sort 

#include<iostream>
using  namespace std;
void insertionSort(int array[], int n){
    for(int i=1; i<n; i++){
        int key=array[i];
        int j=i-1;
        while(j>=0&&array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}
void printarray(int array[],int n){
   for(int i=0;i<n;i++)
   {
    cout<<array[i]<<",";
   }
   
}

int main(){
   int n;
    cout<<"Enter the number of element: "<<endl;
    cin>>n;
    int array[n];
    cout<<"Enter the "<<n<<" element : ";
    for(int i=0;i<n;i++){
       cin>>array[i];
    }
    cout<<"The element of array is : ";
    printarray(array,n);
    cout<<endl;
    insertionSort(array,n);
    cout<<"the sorted array is : ";
    printarray(array,n);

}

  
