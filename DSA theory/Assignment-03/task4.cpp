// Task 4 20 Marks
// Implement a stack-based evaluator for postfix expressions.
// Stack-Based Approach:
// 1. Initialize an empty stack.
// 2. Scan the expression token by token (numbers or operators): If the token is a number, push
// it onto the stack. If the token is an operator (+, -, *, /): Pop the top two numbers from the
// stack (first popped = right operand, second popped = left operand).
// 3. Apply the operator and push the result back onto the stack.
// 4. After scanning, the final result is the only number left in the stack.

// #include <iostream>
// #include <sstream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// class Stack {
// private:
//     Node* top;
// public:
//     Stack(){
//         top=NULL;
//     }

//     void push(int val) {
//         Node* newNode = new Node(val);
//         newNode->next = top;
//         top = newNode;
//     }

//     void pop() {
//         if (top == NULL) {
//             return;
//         }
//          Node* temp=top;
//         top=top->next;
//         delete temp;
//     }

//     int peek() {
//         if(top==NULL){
//             return -1;
//         }
//         return top->data;
//     }

//     bool isEmpty() {
//         return top == NULL;
//     }
// };

// int evaluatePostfix(const char exp[]) {
//     Stack st;
//           stringstream ss(exp);
//     string token;
//    while (ss >> token) {
//         if (isdigit(token[0])) {
//             st.push(stoi(token));
//           if (isdigit(token[0])) {
//             st.push(stoi(token));
//         } else {
//             int right=st.peek();
//             st.pop();
//             int left=st.peek();
//             st.pop();
//             int result=0;
//             switch (token[0]) {
//                 case '+':
//                  result=left+right;
//                  break;
//                 case '-':
//                  result=left-right;
//                  break;
//                 case '*':
//                  result=left*right;
//                  break;
//                 case '/':
//                  result=left/right;
//                  break;
//                 default:
//                     cout<<"Invalid operator!"<<endl;
//                     return 0;
//             }
//             st.push(result);
//         }
//     }
//    }
//     int finalAnswer=st.peek();
//     st.pop();
//     return finalAnswer;
// }

// int main() {
//     string user;
//     cout<<"Enter a postfix expression : ";
//     getline(cin, user);
//     cout<<"Result = "<<evaluatePostfix(user.c_str())<<endl;
//     return 0;
// }

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int v)
    {
        data = v;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    void push(int v)
    {
        Node *n = new Node(v);
        n->next = top;
        top = n;
    }

    int pop()
    {
        int v = top->data;
        Node *t = top;
        top = top->next;
        delete t;
        return v;
    }

    int evaluate(string exp)
    {

        for (int i = 0; i < exp.length(); i++)
        { 
            char ch = exp[i];

            if (ch >= '0' && ch <= '9')
            {
                push(ch - '0');
            }
            else
            {
                int b = pop(); // right operand
                int a = pop(); // left operand

                if (ch == '+')
                    {
                        push(a + b);
                    }
                else if (ch == '-')
                 {
                       push(a - b);
                 }
                else if (ch == '*')
                 {
                       push(a * b);
                 }
                else if (ch == '/')
                   {
                     push(a / b);
                   }
            }
        }
        return pop();
    }
};

int main()
{
    Stack s;
    string exp;

    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << s.evaluate(exp);
    return 0;
}
