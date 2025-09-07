// selection sort


#include<iostream>
using namespace std;
void selectionSort(int array[],int n){
     for (int i=0;i<n-1;i++)
     {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if (array[j]<array[min])   // So the rule is: Use < → ascending,  Use > → descending 
            {
               min=j;
            }
        }
        swap(array[i],array[min]);
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
    selectionSort(array,n);
     cout<<"the sorted array is : ";
    printarray(array,n);

    
}

