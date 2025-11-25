#include<iostream>
using namespace std;
// struct node{
//     int data;
//     node* next;
//     node()
//     {
//         data=v;
//         next=nullptr;
//     }
// }
// node* head=nullptr;
// void insert(int v)
// {
//     node* newnode=new node(v);
//     if (head==nullptr)
//     {
//         head=newnode;
//         newnode-next=head;
//     }
//     else{
//         node* temp=head;
//         while(temp->next!=head)
//         {
//             temp=temp->next;
//         }
//         temp->next=newnode;
//         newnode->next=head;
//     }
// }


int stack[n];
int top=-1;

void push()
{
    int n;
    cout<<"Enter the value";
    cin>>n;
    if(top==n-1)
    {
        cout<<"Stact is full";
    }
    else{
        top++;
        stack[top]=value;
    }

}
void pop()
{
    if(top==-1)
    {
        cout<<"Stack is empty";
    }
    else{
        int v;
        v=stack[top];
        top--;
        cout<<v;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
}