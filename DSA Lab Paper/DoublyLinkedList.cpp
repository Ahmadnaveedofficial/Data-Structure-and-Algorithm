#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    int rollNo;
    int marks;
    Node *next;
    Node *prev;
    Node(string name, int rollNo, int marks)
    {
        this->name = name;
        this->marks = marks;
        this->rollNo = rollNo;
        next = prev = NULL;
    }
};

class DoublyList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void insertAtStart(string name, int rollNo, int marks)
    {
        Node *newNode = new Node(name, rollNo, marks);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
    }

    void insertAtLast(string name, int rollNo, int marks)
    {
        Node *newNode = new Node(name, rollNo, marks);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void display()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << "[Name: " << temp->name
                 << ", Roll: " << temp->rollNo
                 << ", Marks: " << temp->marks << "] <==> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "Doubly Linked List is Empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "Doubly Linked List is Empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    void insertAtPosition(int pos, string name, int rollNo, int marks)
    {
        if (pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            insertAtStart(name, rollNo, marks);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *newNode = new Node(name, rollNo, marks);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        temp->next = newNode;
    }

    void deleteAtPosition(int pos)
    {
        if (pos < 1 || head == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteAtStart();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2->next != NULL)
        {
            temp2->next->prev = temp;
        }
        else
        {
            tail = temp;
        }
        delete temp2;
    }

    void reverse(){
        Node* current =head;
        Node* next=NULL;

        while(current!=NULL){
            next=current->prev;
            current->prev=current->next;
            current->next=next;
            current=current->prev;
        }
        if(next!=NULL){
            head=next->prev;
    }
}

// Search and Update: update marks of a node by roll number
void searchAndUpdate(int rollNo, int newMarks) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            temp->marks = newMarks;
            cout << "Updated marks of " << temp->name << " to " << newMarks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node with Roll No " << rollNo << " not found" << endl;
}

// Search and Delete: delete node by roll number
void searchAndDelete(int rollNo) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            if (temp == head) {
                deleteAtStart();
            } else if (temp == tail) {
                deleteAtEnd();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            cout << "Deleted node with Roll No " << rollNo << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node with Roll No " << rollNo << " not found" << endl;
}

};

int main()
{
    DoublyList l;
    l.insertAtStart("Ahmad Naveed", 149, 89);
    l.insertAtStart("Mohsin Naveed", 117, 87);
    l.insertAtStart("Ahsan Naveed", 97, 78);
    l.insertAtLast("Nawab", 353, 73);

    l.display();
    cout << endl;

    l.deleteAtStart();
    l.display();

    l.deleteAtEnd();
    cout << endl;
    l.display();

    l.insertAtPosition(2, "Inserted Mid", 200, 90);
    l.display();

    l.deleteAtPosition(2);
    l.display();

    l.reverse();
    cout << "Reversed List: " << endl;
    l.display();
    l.searchAndUpdate(117, 95);
    l.display();
    l.searchAndDelete(149);
    l.display();
    
    return 0;
}