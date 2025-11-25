// Task 2 20 Marks
// Write a C++ program to implement Queue using linked list. Include functions to
// • search an element from queue and update that value
// • find maximum value from queue
// • reverse the elements within queue
// • copy the elements of one queue to another in such a way that the order of the elements
// should remain same within both queues.


// #include <iostream>
// using namespace std;
// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };
// class Queue {
// private:
//     Node* front;
//     Node* rear;
// public:
//     Queue() {
//         front =rear = NULL;
//     }
//     void enqueue(int val) {
//         Node* newNode = new Node(val);
//        if(front==NULL){
//         front=rear=newNode;
//         return;
//        }
//          rear->next=newNode;
//          rear=newNode;
//     }
//     void dequeue() {
//         if (front == NULL) {
//             cout << "Queue is empty. Cannot dequeue." << endl;
//             return;
//         }
//         Node* temp = front;
//         front = front->next;
//         delete temp;
//         temp = NULL;
//     }

//     bool isEmpty() {
//         return front == NULL;
//     }
//     int peek() {
//         if (front == NULL) {
//             cout << "Queue is empty!" << endl;
//             return -1;
//         }
//         return front->data;
//     }
//     bool searchAndUpdate(int oldVal, int newVal) {
//         Node* current = front;
//         while (current != NULL) {
//             if (current->data == oldVal) {
//                 current->data = newVal;
//                 return true;
//             }
//             current = current->next;
//         }
//         return false;
//     }
//     int findMax() {
//         if (front == NULL) {
//             cout << "Queue is empty." << endl;
//             return -1;
//         }
//         int maxVal = front->data;
//         Node* current = front->next;
//         while (current != NULL) {
//             if (current->data > maxVal) {
//                 maxVal = current->data;
//             }
//             current = current->next;
//         }
//         return maxVal;
//     }
//     void reverse() {
//         Node* prev = NULL;
//         Node* current = front;
//         Node* next = NULL;
//         rear = front; // After reversal, the front will become rear
//         while (current != NULL) {
//             next = current->next;
//             current->next = prev;
//             prev = current;
//             current = next;
//         }
//         front = prev;
//     }
//     void copyQueue(Queue& source) {
//         if (source.front == NULL) {
//             front = rear = NULL;
//             return;
//         }
//         Node* current = source.front;
//         while (current != NULL) {
//             enqueue(current->data);
//             current = current->next;
//         }
//     }
//     void display() {
//         Node* current = front;
//         while (current) {
//             cout << current->data << " ";
//             current = current->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Queue queue;
//     queue.enqueue(10);
//     queue.enqueue(20);
//     queue.enqueue(30);

//     cout << "Original Queue: ";
//     queue.display();

//     if (queue.searchAndUpdate(20, 25)){
//         cout << "After updating 20 to 25: ";
//     }else{
//          cout << "Element not found: ";
//     }
       
//     queue.display();

//     cout << "Maximum value in queue: " << queue.findMax() << endl;

//     queue.reverse();
//     cout << "Reversed Queue: ";
//     queue.display();

//     Queue copiedQueue;
//     copiedQueue.copyQueue(queue);
//     cout << "Copied Queue: ";
//     copiedQueue.display();

//     return 0;
// }



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

    int Dequeue() {
        if (front==NULL){
            return -1;   
        }
        Node* temp=front;
        int value=temp->data;
        front=front->next;
        if(front==NULL) {
            rear=NULL;
        }
        delete temp;
        return value;
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