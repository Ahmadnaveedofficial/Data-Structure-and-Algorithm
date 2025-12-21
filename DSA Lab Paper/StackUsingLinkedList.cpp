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