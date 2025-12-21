#include <iostream>
using namespace std;

class stack
{
private:
    int *array;
    int top;
    int size;

public:
    stack(int s)
    {
        size = s;
        array = new int[size];
        top = -1;
    }

    void push(int value){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        array[top]=value;
        cout<<"Pushed value: "<<value<<endl;           
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Popped value: "<<array[top]<<endl;
        top--;
    }

    void display(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Stack elements are:"<<endl;
        for(int i=0;i<=top;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    
    bool search(int value){
        for (int i=0;i<=top;i++){
            if(array[i]==value){
                return true;
            }
        }
        return false;
    }

    void reverse(){
        int start=0;
        int end=top;
       while(start<end){
        int temp=array[start];
        array[start]=array[end];
        array[end]=temp;
        start++;
        end--;
       }
       cout<<"reverse stack is: ";
    }

    stack(const stack&other){
        size=other.size;
        top=other.top;
        array=new int [size];
        for(int i=0;i<=top;i++){
            array[i]=other.array[i];
        }
    }


    void removeValue(int value) {
    if(top==-1) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    int i;
    for(i = 0; i <= top; i++) {
        if(array[i] == value) {
            break;
        }
    }

    if(i>top) {
        cout<<value<<" not found in stack"<<endl;
        return;
    }
    for(int j=i;j<top;j++) {
        array[j]=array[j + 1];
    }

    top--;
    cout<<value<<" removed from stack."<<endl;
}

};

int main()
{
    int n;
    cout<<"Enter stack size: ";
    cin>>n;

    stack s(n);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.pop();
    s.display();
    int x=10;
    if(s.search(x)){
        cout<<x<<" is found in stack"<<endl;
    }else{
           cout<<x<<" is not found in stack"<<endl;
    }
    s.display();
    s.reverse();
    s.display();

    stack s1=s;
    s1.display();

    s.removeValue(22);
    s.display();

    return 0;
}
