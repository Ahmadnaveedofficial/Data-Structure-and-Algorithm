#include<iostream>
using namespace std;

class Node {
public:
    string name;
    int rollNO;
    int marks;
    Node* next;
    Node(string name, int rollNO, int marks) {
        this->name = name;
        this->rollNO = rollNO;
        this->marks = marks;
        this->next = nullptr;
    }
};

class CircularList{
private:
    Node* head;
    Node* tail;
public:
   CircularList(){
    head=NULL;
    tail=NULL;
   }

   void insertAtStart(string name, int rollNO, int marks) {
       Node* newNode = new Node(name, rollNO, marks);
       if(head==NULL){
        head=tail=newNode;
        tail->next=head;
        return;
       }
       newNode->next=head;
         head = newNode;
         tail->next = head; 
   }
   
   void InsertAtEnd(string name, int rollNO, int marks) {
       Node* newNode = new Node(name, rollNO, marks); 
         if(head==NULL){
          head=tail=newNode;
          tail->next=head;
          return;
         }
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
   }

   void display(){
    Node*temp=head;
    if(temp==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    do{
        cout<<"[ Name: "<<temp->name<<", Roll No: "<<temp->rollNO<<", Marks: "<<temp->marks<<" ] ---> ";
        temp=temp->next;
    }while(temp!=head);
    cout<<"back to head"<<endl;  
   }

   void deteleAtStart(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head=tail=NULL;
        return;
    }
    Node* temp=head;
    head=head->next;
    tail->next=head;
    temp->next=NULL;
    delete temp;
   }

   void deleteAtEnd(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head==tail){
        delete head;
        head=tail=NULL;
        return;
    }
   Node *temp=tail;
   Node * prev=head;
    while(prev->next!=tail){
     prev=prev->next;
   }
    tail=prev;
    tail->next=head;
    temp->next=NULL;
    delete temp;
   }

   void insertAtPosition(int pos, string name, int rollNo,int marks){
       Node *newNode=new Node(name,rollNo,marks);
       if(pos<1){
        cout<<"Invalid Postion"<<endl;
        return;
       }
       if(pos==1){
        insertAtStart(name,rollNo,marks);
        return;
       }else{
        Node* temp =head;
        for(int i =1 ;i<pos-1 &&temp->next!=head;i++){
            temp=temp->next;
        }
            newNode->next=temp->next; 
            temp->next=newNode;
        if(temp==tail){
            tail=newNode;
        }
       }
   }

   void deleteAtPostion(int pos){
     if (head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

      if(pos<1){
        cout<<"Invalid Postion"<<endl;
        return;
       }
       if(pos==1){
       deteleAtStart();
        return;
       }
       Node*temp=head;
       Node*prev=NULL;
       for(int i=1;i<pos && temp->next!=head;i++){
        prev=temp;
        temp=temp->next;
       }
       if (temp == head) {
     cout<<"Position out of range"<<endl;
        return;
    }
        prev->next=temp->next;
        if(temp==tail){
        tail=prev;
        tail->next=head;
       }
       temp->next=NULL;
       delete temp;
       }
   


};

int main(){
    CircularList cl;
    cl.insertAtStart("Ahmad Naveed", 1, 85);
    cl.insertAtStart("Mohsin Naveed", 2, 90);
    cl.insertAtStart("Ahsan Naveed", 3, 95);
    cl.display();
    cout<<endl;
    cl.InsertAtEnd("Nawab", 4, 88);
    cl.InsertAtEnd("Ibraheem", 5, 92);
    cl.display();
    cout<<endl;
    cl.deteleAtStart();
    cl.display();
    cout<<endl;
    cl.deleteAtEnd();
    cl.display();
    cout<<endl;
    cl.insertAtPosition(1,"Saqib", 5, 92);
    cl.display();
    return 0;
}