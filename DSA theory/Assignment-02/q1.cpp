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

void sorting() {
    if (!head||!head->next) {
        cout<<"List contains one or no elements"<<endl;
        return;
    }

    Node* sorted=NULL;
    Node* current=head;

    while(current!=NULL){
        Node* nextNode=current->next;
        if(sorted==NULL||sorted->data>=current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp=sorted;
            while(temp->next!=NULL&&temp->next->data< current->data) {
                temp=temp->next;
            }
            current->next=temp->next;
            temp->next=current;
        }

        current=nextNode;
    }

    head=sorted;
}


void removeDuplicates() {
    if (!head) return; 
    
    Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next; 
            delete duplicate; 
        } else {
            current = current->next; 
        }
    }
}

void swapNodes(){
  if (head==NULL || head->next==NULL){
    return;
  }
  Node* first=head;
  Node* Second=head->next;
  Node* prev=NULL;
  while(first!=NULL&& Second!=NULL){
    Node* third=Second->next;
    Second->next=first;
    first->next=third;
    if(prev!=NULL){
          prev->next=Second;
    }else{
      head=Second;
    }
    prev=first;
    first=third;
    if(third!=NULL){
      Second=third->next;
    }else{
      Second=NULL;
    }
  }

  
  }
  void evenOdd() {
   Node* head1 = NULL;  // even list ka head
Node* head2 = NULL;  // odd list ka head
Node* tail1 = NULL;  // even list ka tail (last node)
Node* tail2 = NULL;  // odd list ka tail (last node)


    Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (head1 == NULL) {
                head1 = temp;
                tail1 = temp;
            } else {
                tail1->next = temp;
                tail1 = tail1->next;
            }
        } else {
            if (head2 == NULL) {
                head2 = temp;
                tail2 = temp;
            } else {
                tail2->next = temp;
                tail2 = tail2->next;
            }
        }
        temp = temp->next;
    }
      
// List me saare even elements pehle,aur saare odd elements baad me honge.
    // if (tail1 != NULL) {
    //     tail1->next = head2;
    //     if (tail2 != NULL)
    //         tail2->next = NULL;
    //     head = head1;
    // } else {
    //     tail2->next = NULL;
    //     head = head2;
    // }

    // List me saare odd elements pehle,aur saare even elements baad me honge.
    if(tail2!=NULL){
      tail2->next=head1;
      if(tail1!=NULL){
        tail1->next=NULL;
      }
      head=head2;
    }else{
      tail1->next=NULL;
      head=head1;
    }


}

  void reverseList(){
    Node*prev=NULL;
    Node*current=head;
    Node*nextNode=NULL;
    while(current!=NULL){
      nextNode=current->next;
      current->next=prev;
      prev=current;
      current=nextNode;
    }
    head=prev;
  }

};

 int main(){
  LinkedList li;
  cout<<"Inserting nodes..."<<endl;
  // li.insertNode(8);
  // li.insertNode(1);
  // li.insertNode(3);
  // li.insertNode(4);
  // li.insertNode(2);
  // li.insertNode(1); 
  // li.displayList();
  // cout<<endl;
  // li.middleNode(false);


  // li.insertNode(8);
  // li.insertNode(1);
  // li.insertNode(3); 
  // li.insertNode(4);
  // li.insertNode(2);
  // li.insertNode(1);
  // li.displayList();
  // cout<<endl;
  // li.makeMiddleHead(false);
  // li.displayList();

  
  // li.insertNode(3);
  // li.insertNode(8);
  // li.insertNode(3);
  // li.insertNode(2);
  // li.insertNode(4);
  // li.displayList();
  // cout<<endl;
  // li.sorting();
  // li.displayList();
  
  // li.insertNode(8);
  // li.insertNode(4); 
  // li.insertNode(3);
  // li.insertNode(7);
  // li.insertNode(2);
  // li.displayList();
  // cout<<endl;
  // li.removeDuplicates();
  // li.displayList();

// li.insertNode(0);
//   li.insertNode(2);
//   li.insertNode(3);
//   li.insertNode(2);
//   li.insertNode(6);
//   li.displayList();
//   cout<<endl;
//   li.swapNodes();
//   li.displayList();


  li.insertNode(0);
  li.insertNode(2);
  li.insertNode(3);
  li.insertNode(2);
  li.insertNode(1);
  li.displayList();
  cout<<endl;
  li.evenOdd();
  li.displayList();
  cout<<endl;



  // li.insertNode(0);
  // li.insertNode(9);
  // li.insertNode(3);
  // li.insertNode(2);
  // li.insertNode(1);
  // li.displayList();
  // cout<<endl;
  // li.reverseList();
  // li.displayList();

}

