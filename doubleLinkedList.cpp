#include<iostream>
using namespace std;

class Node{
    public:
 int data;
 Node* next;
 Node* prev;
 Node(int data){
    this->data=data;
    next=prev=NULL;
 }
};
class DoublyList{
    Node*head;
    Node* tail;
    public:
    DoublyList(){
        head=tail=NULL;
    }
    void insertAtStart(int data){
        Node* newNode=new Node(data);
     if(head==NULL){
        head=tail=newNode;
     }else{
      newNode->next=head;
     head->prev=newNode;
     head=newNode;
     }
 
    }
    void insertAtEnd(int data){
      Node*newNode=new Node(data);
      Node*temp=head;
      if(head==NULL){
        head=tail=newNode;
      }else{
         newNode->prev=tail;
         tail->next=newNode;
         tail=newNode;
      }
    }
    void insertAtPostion(int data,int pos){
        Node*newNode=new Node(data);
        if(pos<1){
            cout<<"Invalid position:"<<endl;
        }else if (pos==1)
        {
            insertAtStart(data); 
        }else{
            Node*temp=head;
            for(int i=1;i<pos-1&& temp!=NULL;i++){       // insert  before the position use pos-1 and after position use only pos 
                temp=temp->next;
            }
             if(temp!=NULL){
                    newNode->next=temp->next;
                    newNode->prev=temp;
                    temp->next->prev=newNode;
                    temp->next=newNode;
             }
        }
    }

    void deleteAtStart(){
        if(head!=NULL){
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;

        }
    }
    void deleteAtEnd(){
        if(tail!=NULL){
            Node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
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
            if(temp!=NULL && temp->next!=NULL){
                Node* temp2=temp->next;
                temp->next=temp2->next;
                if(temp2->next!=NULL){
                    temp2->next->prev=temp;
                }
                else{
                    tail=temp;
                }
                temp2->next=NULL;
                temp2->prev=NULL;
                delete temp2;
            }
        }
    }

    void display(){
    Node*temp=head;
    while(temp!=NULL){
        cout<<"Data: "<<temp->data<<endl;
        temp=temp->next;
    }
}
};


int main(){
    DoublyList li;
    li.insertAtStart(1);
    li.insertAtStart(2);
    li.insertAtStart(3);
    li.insertAtEnd(4);
    li.insertAtPostion(3,4);
    // li.deleteAtStart();
    // li.deleteAtEnd();
    li.deleteAtPosition(3);
    li.display();
}