#include<iostream>
using namespace std;

class stack{
    private:
    int *array;
    int top;
    int size;
    public:
    stack(int s){
   size=s;
   array=new int[size];
   top=-1;  
    }  
   
    void push(int data){
        if(top==size-1){
         cout<<"stack is overflow "<<endl;
         return;
        }
        top++;
        array[top]=data;
        cout<<"pushed value: "<<data<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"stack is underflow"<<endl;
            return;
        }
        cout<<"poped value :"<<array[top]<<endl;
        top--;

    }

    bool search(int key){
        for(int i=0;i<=top;i++){
            if(array[i]==key){
                return true;
            }
        }
        return false;
    }

    void reverse(){
        int start=0;
        int end=top;
        while(start<end){
            swap(array[start],array[end]);
        
            
            start++;
          end--;
        }
    }

    void display(){
     if(top==-1){
        cout<<"stack is empty"<<endl;
        return;
     }
     for(int i=0;i<=top;i++)
     {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}


void removeValue(int key){
       if(top==1){
        cout<<"empty"<<endl; 
        return;
       }
       int i ;
       for(i=0;i<=top;i++){
        if(array[i]==key){
            break;
        }
       }
       if(i>top){
        cout<<"not found"<<endl;
        return;
       }            
       for(int j=i;j<=top;j++){
        array[j]=array[j+1];
       }
       top--;
       cout<<"delete value is "<<key<<endl;
}

  void copyStack( const stack& other){
   size=other.size;
   top=other.top;
   array=new int [size];
   for(int i=0;i<=top;i++){
    array[i]=other.array[i];
   }
  }

  void updateValue(int key ,int newkey){
    if(top==-1){
        cout<<"empty"<<endl;
        return;

    }
    for(int i=0;i<=top;i++){
        if(array[i]==key){
            array[i]=newkey;
            cout<<"old value "<<key<<" change with new value "<<newkey<<endl;
            return;
        }
    }
    cout<<"key not found"<<endl;
  }

};

int main(){
     int n;
    cout<<"Enter stack size: ";
    cin>>n;

    stack s(n);

    s.push(3);
    s.push(2);
    s.push(1);
    s.push(4);
    s.display();
      s.updateValue(2,5);
   s.display();
    stack s1(n);
   s1.copyStack(s);
   cout<<"copy stack is ";
   s1.display();
    s.pop();
    cout<<"after pop of stack"<<endl;
    s.display();
   cout<<s.search(7)<<endl;
   cout<<(s.search(3)?"found":"Not found")<<endl;
   cout<<"reverse stack ";
   s.reverse();
   s.display();
   s.removeValue(1);
   s.display();



}