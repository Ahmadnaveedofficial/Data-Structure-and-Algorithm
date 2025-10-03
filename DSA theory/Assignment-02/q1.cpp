#include <iostream>
using namespace std;
class Node;

class Node{
   public:
   int data;
   Node *next; 
   public:
   Node(int data){
      this->data=data;
      next=NULL;
   }
};

class LinkedList{
    private:
   Node *head;
   public:
   LinkedList(){
    head=NULL;
   }
   void displayList(){
    Node*temp= head;
    if(temp==NULL){
       cout<<"List is Empty";
       return;
    }
    while (temp!=NULL){
      cout<<"Data: "<<temp->data<<endl;
      temp=temp->next;
    }
   }  
     void insertNode(int data){
          Node *temp=new Node(data);
        if (head==NULL){
            head=new Node(data);
            return;
        }
         temp->next=head;
         head=temp;    
     }
     void removeNode(int data){
          if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
          }
          if (head->data==data){
            Node* todelete=head;
            head=head->next;
            delete todelete;
            cout<<"node is delete: "<<data<<endl;
            return;
          }
          Node* temp=head;
          Node* temp2=NULL;
          while(temp!=NULL && temp->data!=data  ){
             temp2=temp;
             temp=temp->next;
          }
          if(temp!=NULL){
            temp2->next=temp->next;
            delete temp;
            cout<<"Node deleted: "<<data<<endl;
          }else{
            cout<<"Node is not Found: "<<data<<endl;
          }
     }
     void searchNode(int data){
        Node* temp=head;
        while (temp!=NULL){
          if (temp->data==data) {
             cout<<"Node is found : "<<data<<endl;
             return;
          }
        temp=temp->next;
        }
            cout<<"Node is not Found: "<<data<<endl;
      
     }
     void updateNode(int data,int newdata){
      Node*temp=head;
      while(temp!=NULL){
      if(temp->data==data){
          temp->data=newdata;
          cout<<"node is updated : "<<data<<" ---> "<<newdata<<endl;
          return;
      }
      temp=temp->next;
      } 
      cout<<"node is not found "<<data<<endl;
    }
    void middleNode( bool getSecondMiddle=false){
           if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
           }
            Node* slow=head;
            Node* fast;
            if(getSecondMiddle){
              fast=head;
            }
            else{
              fast=head->next;
            }
            while (fast!=NULL&&fast->next!=NULL){
              slow=slow->next;
              fast=fast->next->next;
            }
            cout<<"middle node "<<slow->data<<endl;
    }
    
  void makeMiddleHead(bool getSecondMiddle = false) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL) {
        return;  
      }
    Node* slow = head;
    Node* fast;
    if (getSecondMiddle) {
        fast = head;        
    } else {
        fast = head->next;  
    }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middleNode = slow;
    Node*temp=head;
    Node* temp2=head->next;
    while (temp->next != middleNode) {
        temp = temp->next;
    }
     temp->next = head;
     head->next = middleNode->next;
     middleNode->next = temp2;
      head = middleNode;
}


};

int main(){
  LinkedList li;
  cout<<"Inserting nodes..."<<endl;
  li.insertNode(1);
  li.insertNode(2);
  li.insertNode(4);
  li.insertNode(1);
  li.insertNode(2);
  li.insertNode(3);
  
  li.displayList();
  cout<<endl;
  li.middleNode(true);

  li.makeMiddleHead(false);
  li.displayList();
}
