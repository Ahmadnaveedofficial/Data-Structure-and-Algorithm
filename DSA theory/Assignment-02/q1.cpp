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
     void insertNode(int data){
          Node *temp=new Node(data);
        if (head==NULL){
            head=new Node(data);
            return;
        }
         temp->next=head;
         head=temp;    
     }
     void removeNode()
};
