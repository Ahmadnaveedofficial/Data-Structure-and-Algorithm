// Task 3 20 Marks
// Write a function that uses a stack to check if a given string of parentheses ((), [], {}) is
// balanced.
// Stack-Based Approach:
// 1. Initialize an empty stack.
// 2. Scan the string character by character: If an opening bracket ((, [, {) is found, push it onto
// the stack. If a closing bracket (), ], }) is found: Check if the stack is empty → If yes, it's
// unbalanced.
// 3. Pop the top of the stack and check if it matches the closing bracket.
// 4. If they don’t match, the string is unbalanced.
// 5. After scanning, if the stack is empty, the string is balanced; otherwise, it's unbalanced.
// Example:
// • Input: "{[()]}" → Balanced
// • Input: "{[}]" → Unbalanced (closing } doesn’t match [)


#include <iostream>
using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node(char val) {
        data=val;
        next=NULL;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack() { 
        top=NULL; 
    }
    void push(char val) {
        Node* newNode=new Node(val);
        newNode->next=top;
        top=newNode;
    }

    void pop() {
        if (top ==NULL) {
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    char peek(){
        if(top == NULL){
             return '\0';
        }
        return top->data;
    }

    bool isEmpty() {
        return top=NULL;
    }
};

bool isBalanced(const string& str) {
    Stack s;
    for (int i=0;i<str.length(); i++){
        char ch = str[i];
        if (ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }
        else if (ch==')'||ch==']'||ch=='}'){
            if (s.isEmpty()){
                 return false; 
            }
            char top=s.peek();
            s.pop();
            if ((ch==')'&& top!='(')||(ch==']'&& top!='[') || (ch=='}'&& top!='{')) {
                return false;
            }
        }
    }
    return s.isEmpty(); 
}
int main() {
    string input1="{[()]}";
    string input2="{[}]";

    cout<<"Input: "<<input1<< " → " <<(isBalanced(input1) ? "Balanced":"Unbalanced")<<endl;
    cout<<"Input: " <<input2<< " → " <<(isBalanced(input2) ? "Balanced":"Unbalanced")<<endl;

    string userInput;
    cout<<"Enter a string of brackets: ";
    cin>>userInput;
    cout<<(isBalanced(userInput) ? "Balanced" : "Unbalanced")<<endl;

    return 0;
}