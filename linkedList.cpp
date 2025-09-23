#include <iostream>
using namespace std;
class Node;
Node *head=NULL;
class Node{
    public:
    string name;
    int roll;
    float cgpa;
    Node* next;
    Node(string n,int r,float c){
        name=n;
        roll=r;
        cgpa=c;
        next=NULL;
    }
  
};
  class List{
    public:
    void insertAtStart(string n,int r,float c){
      if(head==NULL){  // list is empty
            head=new Node(n,r,c);
            return;
      }
        Node* temp=new Node(n,r,c);
        temp->next=head;
        head=temp;
    }

 void insertAtEnd(string n,int r,float c){
      if(head==NULL){  // list is empty
            head=new Node(n,r,c);
            return;
      }
        
        Node* temp=new Node(n,r,c);
        Node* t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=temp;
    }
    void insertAtPosition(string n,int r,float c,int pos){
        if(pos<1){
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos==1){
            insertAtStart(n,r,c);
            return;
        }
        else{
            Node *NewNode=new Node(n,r,c);
            Node* temp=head;
            for(int i=1;i<pos-1;i++){  // insert  before the position use pos-1 and after position use only pos 
                 temp=temp->next;
                    if(temp==NULL){
                        break;
                    }
                }
                if(temp!=NULL){
                    NewNode->next=temp->next;
                    temp->next=NewNode;
                }
            }
        }

    void  deleteAtStart(){
        if(head!=NULL){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    void deleteAtEnd(){
        if(head!=NULL){
           Node *temp=head;
   while(temp->next->next!=NULL){
         temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    }
    void deleteAtPosition(int pos){
        if(pos<1){
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos==1){
            deleteAtStart();
            return;
        }
        else{
            Node* temp=head;
            for(int i=1;i<pos-1;i++){   // delete before the position use pos-1 and after position use only pos
                temp=temp->next;
                if(temp==NULL){
                    break;
                }
            }
            if(temp!=NULL){
                Node* temp2=temp->next;
                temp->next=temp2->next;
                delete temp2;
            }
        }
    }
  void display(){
      Node* temp=head;
      if(temp==NULL){  // list is empty
          cout<<"List is empty"<<endl;
          return;
      }
      while(temp!=NULL){
          cout<<"Name: "<<temp->name<<endl;
          cout<<"Roll: "<<temp->roll<<endl;
          cout<<"CGPA: "<<temp->cgpa<<endl;
          cout<<"\t|"<<endl;
          temp=temp->next;
      }
  }
};
int main() {
     List myList;
     myList.insertAtStart("Talha",102,2.6);
    myList.insertAtStart("Mohsin",103,3.7);
    myList.insertAtEnd("Ahmad",101,3.9);
    myList.insertAtEnd("Ali",105,3.5);
    myList.insertAtStart("Saqib",104,2.8);
    myList.insertAtPosition("Hassan",106,3.2,3);
    myList.insertAtPosition("Ahsan",107,3.1,1);
    myList.insertAtPosition("Haris",108,3.4,10); // Invalid Position
    myList.deleteAtPosition(2);
    myList.display();
    return 0;
}
