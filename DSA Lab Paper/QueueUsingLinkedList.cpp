#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data=d;
        next=NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }
    void Enqueue(int d) {
        Node* newNode = new Node(d);
        if (rear==NULL) {
            front=rear=newNode;
            return;
        } else {
            rear->next=newNode;
            rear=newNode;
        }
    }

    void Dequeue() {
        if (front==NULL){
            cout<<"Queue is empty. Cannot dequeue."<<endl;
            return;   
        }
        Node* temp=front;
        int value=temp->data;
        front=front->next;
        if(front==NULL) {
            rear=NULL;
        }
        delete temp;
        cout<<"Dequeued value: "<<value<<endl;
    }

    void search_update(int searchdata, int updatedata) {
        Node* temp=front;
        while (temp!=NULL) {
            if (temp->data==searchdata) {
                temp->data=updatedata;
                cout<<"Updated "<<searchdata<<" to "<<updatedata<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Not found"<<endl;
    }

    void maximum(){
        if (front==NULL) {
            cout<<"No elements"<<endl;
            return;
        }
        Node* temp=front;
        int max=front->data;   
        while(temp!=NULL) {
            if (temp->data>max){
                 max=temp->data;
            }
            temp = temp->next;
        }
        cout<<"Maximum value = "<<max<<endl;
    }

    void reverse() {
        Node*prev=NULL;
        Node*current=front;
        Node*next=NULL;
        rear=front;
        while(current!=NULL) {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        front=prev;
    }

    void display() {
        Node* temp=front;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void copy(Queue &destination) {
        Node* temp=front;
        while (temp!=NULL) {
            destination.Enqueue(temp->data);
            temp=temp->next;
        }
    }
};

int main() {
    Queue q1;
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);

    cout<<"Original Queue: ";
    q1.display();

    q1.search_update(20, 99);
    q1.display();

    q1.maximum();

    q1.reverse();
    cout<<"Reversed Queue: ";
    q1.display();

    Queue q2;
    q1.copy(q2);
    cout<<"Copied Queue: ";
    q2.display();

    return 0;
}