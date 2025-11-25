#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node(string s) {
        name=s;
        next=NULL;
    }
};

class StackLL {
private:
    Node* top; 
public:
    StackLL() {
        top = NULL;
    }

    void push(string s) {
        Node* n = new Node(s);
        n->next = top;
        top = n;
    }

    void pop() {
        if (top != NULL) {
            Node* temp = top;
            cout << "Popped: " << temp->name << endl;
            top = top->next;
            delete temp;
        } else {
            cout << "Stack is empty!\n";
        }
    }

    void display() {
        if (top==NULL) {
            cout<<"Stack is empty!\n";
            return;
        }
        cout<<"Stack contents:\n";
        Node* temp=top;
        while(temp!=NULL) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
        void search(string s) {
        Node* temp=top;
        bool found=false;
        while (temp!=NULL) {
            if (temp->name==s) {
                found=true;
                break;
            }
            temp = temp->next;
        }
        if (found)
           {
             cout<<s<<" found in stack."<<endl;
           }
        else{
             cout<<s<<" not found in stack."<<endl;
        }
            
    }
};

int main() {
    StackLL s;

    s.push("Ahmad");
    s.push("Mohsin");
    s.push("Ahsan");
    s.push("Ibraheem");
    s.push("Nawab");
    s.display();
    cout <<endl;
    s.pop();
    s.display();
    return 0;
}
