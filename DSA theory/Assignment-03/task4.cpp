// Task 4 20 Marks
// Implement a stack-based evaluator for postfix expressions.
// Stack-Based Approach:
// 1. Initialize an empty stack.
// 2. Scan the expression token by token (numbers or operators): If the token is a number, push
// it onto the stack. If the token is an operator (+, -, *, /): Pop the top two numbers from the
// stack (first popped = right operand, second popped = left operand).
// 3. Apply the operator and push the result back onto the stack.
// 4. After scanning, the final result is the only number left in the stack.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() { 
        top = NULL; 
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) return -1;
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int evaluatePostfix(char exp[]) {
    Stack st;
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == ' ')
           {
            continue;
           }
        if (c >= '0' && c <= '9') {
            st.push(c - '0');  
        }
        else {
            int right = st.peek();
            st.pop();
            int left = st.peek();
            st.pop();
            int result = 0;
            switch (c) {
                case '+': 
                result = left + right;
                 break;
                case '-': 
                result = left - right;
                 break;
                case '*': 
                result = left * right;
                 break;
                case '/': 
                result = left / right;
                 break;
                default:
                    cout<<"Invalid operator!"<<endl;
                    return 0;
            }

            st.push(result);
        }
    }
    int finalAnswer = st.peek();
    st.pop();
    return finalAnswer;
}


int main() {
    string exp1="10 20 + 30 *";   // (10+20)*30 = 900
    string exp2="100 20 / 5 +";   // (100/20)+5 = 10

    cout<<"Postfix: "<<exp1<<" = "<<evaluatePostfix(exp1)<<endl;
    cout<<"Postfix: "<<exp2<<" = "<<evaluatePostfix(exp2)<<endl;
    string user;
    cout<<"Enter a postfix expression (tokens separated by space): ";
    getline(cin, user);
    cout<<"Result = "<<evaluatePostfix(user)<<endl;

    return 0;
}