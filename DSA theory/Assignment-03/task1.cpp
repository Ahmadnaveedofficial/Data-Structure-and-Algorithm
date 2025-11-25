// Task 1 
// Write a C++ program to implement stack using linked list. Include functions to
// • search an element from stack and update that value
// • find maximum value from stack
// • reverse the elements within stack
// • copy the elements of one stack to another in such a way that the order of the elements
// should remain same within both stacks.

// #include <iostream>
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
//     Stack() {
//         top = NULL;
//     }
//     void push(int val) {
//         Node* newNode = new Node(val);
//         newNode->next = top;
//         top = newNode;
//     }

//     void pop() {
//         if (top == NULL) {
//             cout << "Stack is empty. Cannot pop." << endl;
//             return;
//         }
//         Node* temp = top;
//         top = top->next;
//         delete temp;
//     }
//     bool isEmpty() {
//         return top == NULL;
//     }

//     int peek() {
//         if (top == NULL) {
//             cout << "Stack is empty!" << endl;
//             return -1;
//         }
//         return top->data;
//     }
//     bool searchAndUpdate(int oldVal, int newVal) {
//         Node* current = top;
//         while (current != NULL) {
//             if (current->data == oldVal) {
//                 current->data = newVal;
//                 return true;
//             }
//             current = current->next;
//         }
//         return false;
//     }
//     int findMax() {
//         if (top == NULL) {
//             cout << "Stack is empty." << endl;
//             return -1;
//         }
//         int maxVal = top->data;
//         Node* current = top->next;
//         while (current != NULL) {
//             if (current->data > maxVal) {
//                 maxVal = current->data;
//             }
//             current = current->next;
//         }
//         return maxVal;
//     }

//     void reverse() {
//         Node* prev = NULL;
//         Node* current = top;
//         Node* next = NULL;
//         while (current != NULL) {
//             next = current->next;
//             current->next = prev;
//             prev = current;
//             current = next;
//         }
//         top = prev;
//     }

//     // Copy stack to another preserve order
//     Stack copy() {
//         Stack newStack;
//         if (top == NULL) {
//             cout << "Source stack is empty!" << endl;
//             return newStack;
//         }

//         // Reverse into tempStack
//         Stack tempStack;
//         Node* current = top;
//         while (current) {
//             tempStack.push(current->data);
//             current = current->next;
//         }

//         // Copy while preserving order
//         while (!tempStack.isEmpty()) {
//             newStack.push(tempStack.peek());
//             tempStack.pop();
//         }

//         return newStack;
//     }
//     void display() {
//         Node* current = top;
//         while (current) {
//             cout << current->data << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Stack stack;
//     stack.push(10);
//     stack.push(20);
//     stack.push(30);

//     cout<<"Original Stack: ";
//     stack.display();

//     if (stack.searchAndUpdate(20, 25)){
//         cout<<"After updating 20 to 25: ";
//     }else{
//          cout<<"Element not found: ";
//     }
       
//     stack.display();

//     cout<<"Maximum value in stack: "<<stack.findMax()<<endl;

//     stack.reverse();
//     cout<<"Reversed Stack: ";
//     stack.display();

//     Stack copiedStack = stack.copy();
//     cout<<"Copied Stack: ";
//     copiedStack.display();

//     return 0;
// }



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};
class Stack {
private:
    Node* Top;  

public:
    Stack() {
        Top = NULL;
    } 

    void Push(int d) {
        Node* newNode=new Node(d);
        newNode->next=Top;
        Top=newNode;
    }

    int Pop() {
        if (Top==NULL) {
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }
        Node* temp=Top;
        int value=temp->data;
        Top=Top->next;
        delete temp;
        return value;
    }

    void search_update(int searchdata, int updatedata) {
        Node* temp=Top;
        while (temp!=NULL){
            if (temp->data==searchdata) {
                cout<<"Found "<<searchdata<<", updating to "<<updatedata<<endl;
                temp->data=updatedata;
                return;
            }
            temp=temp->next;
        }
        cout<<"Value not found!"<<endl;
    }

    void reverse() {
        Node* prev=NULL;
        Node* current=Top;
        Node* next=NULL;

        while (current!=NULL) {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        Top = prev;
    }

    void maximum() {
        if (Top==NULL) {
            cout<<"Stack is empty!"<<endl;
            return;
        }
        Node* temp=Top;
        int max=temp->data; 
        while (temp!=NULL) {
            if (temp->data>max){
                 max=temp->data;
            }
            temp =temp->next;
        }
        cout<<"Maximum value = "<<max<<endl;
    }

    void display() {
        Node* temp = Top;
        cout << "Stack elements: ";
        while (temp!=NULL) {
            cout<<temp->data<< " ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void copy(Stack &destination) {
        Stack tempStack;
        Node* temp=Top;
        while(temp!=NULL) {
            tempStack.Push(temp->data);
            temp=temp->next;
        }

        while (tempStack.Top!=NULL) {
            destination.Push(tempStack.Pop());
        }
    }
};

int main() {
    Stack s1;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);

    cout<<"Original Stack:"<<endl;
    s1.display();

    s1.search_update(20, 99);
    s1.display();

    s1.maximum();

    s1.reverse();
    cout<<"Reversed Stack:"<<endl;
    s1.display();

    Stack s2;
    s1.copy(s2);
    cout<<"Copied Stack:"<<endl;
    s2.display();

    return 0;
}