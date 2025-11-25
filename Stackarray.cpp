class Stack
{
string arr[100];
int top;
public:
Stack()
{
top=-1;
}
void push(int r)
{
if(top!=99)
{
top++;
arr[top]=r;

}
else{
cout<<"Stack is full\n";
}


}
void pop()
{
if(top<0)
{
cout<<"Stack is empty\n";
}
else{
cout<<"Removed from stack: "<<arr[top]<<endl;
top--;


}
}
void display()
{
for(int i=0;i<=top;i++)
{
cout<<arr[i]<<" ";
}
}
};
