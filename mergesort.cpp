// merge sort

#include<iostream>
using namespace std;

void merge(int array[],int left,int mid,int right){
    int n1=mid-left+1;   // size of left subarray
    int n2=right-mid;    // size of right subarray

    int L[n1],R[n2];     // Temporary array
    for (int i=0;i<n1;i++){      // Temporary array of left side
        L[i]=array[left+i];
    }
    for (int i=0;i<n2;i++){         // Temporary array of right side
        R[i]=array[mid+1+i];
    }
    
     // Merge the two arrays
     int i=0,j=0,k=left;
     while (i<n1&&j<n2){
            if (L[i]<=R[j]){    // So the rule is: Use <= → ascending,  Use >= → descending                 
                 array[k]=L[i];
                 i++;
            }else{
                array[k]=R[j];
                j++;
            }
            k++;
     }

      // Copy remaining elements
       while (i<n1)
       {
        array[k]=L[i];
        i++;
        k++;
       }
       while (j<n2)
       {
         array[k]=R[j];
         j++;
         k++;
       }
       
}

void mergeSort(int array[],int left,int right){
        if (left<right)
        {
           int mid=(left+right)/2;
           mergeSort(array,left,mid);
           mergeSort(array,mid+1,right);
           merge(array,left,mid,right);
        }
        
}

void printArray(int array[], int n){
     for (int i=0;i<n;i++){
        cout<<array[i]<<" ";
     }
      cout<<endl;
     
}

int main(){
    int n;
    cout<<"Enter the number of Element that you want to create of an array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the "<<n<<" element ";
    for (int  i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<"Orginal array is ";
    printArray(array,n);
    mergeSort(array,0,n-1);
    cout<<"Sorted array is ";
    printArray(array,n);
}