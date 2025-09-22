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
int main() {
     insertAtStart("Talha",102,2.6);
    insertAtStart("Mohsin",103,3.7);
    insertAtEnd("Ahmad",101,3.9);
    insertAtEnd("Ali",105,3.5);
    insertAtStart("Saqib",104,2.8);
    display();
    return 0;
}