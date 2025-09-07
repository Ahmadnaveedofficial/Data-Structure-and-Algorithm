// bubble sort

#include<iostream>
using namespace std;
void bubbleSort(int array[],int n){
     for (int i=0;i<n-1;i++)
     {
        for (int j=0;j<n-1-i;j++)
        {
            if (array[j]> array[j+1])  // So the rule is: Use > → ascending,  Use < → descending 
            {
                swap(array[j],array[j+1]);
            }
            
        }
        
     }
     
} 

void printarray(int array[],int n){
   for (int i=0;i<n;i++)
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
    bubbleSort(array,n);
     cout<<"the sorted array is : ";
    printarray(array,n);

    
}

