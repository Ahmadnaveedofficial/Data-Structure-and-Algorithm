#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    int rollNo;
    int Marks;
    Node *next;
    Node(string name, int rollNo, int Marks)
    {
        this->name = name;
        this->rollNo = rollNo;
        this->Marks = Marks;
        next = NULL;
    }
};

class SingleList
{
private:
    Node *head;

public:
    SingleList()
    {
        head = NULL;
    }
    void InsertAtStart(string name, int rollNo, int Marks)
    {
        Node *newNode = new Node(name, rollNo, Marks);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void InsertAtLast(string name, int rollNo, int Marks)
    {
        Node *newNode = new Node(name, rollNo, Marks);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void InsertAtPosition(string name, int rollNo, int Marks, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid Positiom" << endl;
            return;
        }
        if (pos == 1)
        {
            InsertAtStart(name, rollNo, Marks);
            return;
        }
        else
        {
            Node *newNode = new Node(name, rollNo, Marks);
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            { // insert  before the position use pos-1 and after position use only pos
                temp = temp->next;
                if (temp == NULL)
                {
                    break;
                }
            }
            if (temp != NULL)
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else
            {
                cout << "Invalid Position" << endl;
            }
        }
    }
    void display()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << "Name: " << temp->name << endl;
            cout << "Roll: " << temp->rollNo << endl;
            cout << "Marks: " << temp->Marks << endl;
            cout << "|" << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void DeleteAtStart()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }
    }
    void DeleteAtEnd()
    {
        if (head == NULL)
        {
            return; // empty list
        }
        if (head->next == NULL)
        { // only one node
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void DeleteAtPosition(int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 1)
        {
            DeleteAtStart();
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    break;
                }
            }
            if (temp != NULL)
            {
                Node *temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
                temp1 = NULL;
            }
        }
    }
    void SearchAndDelete(int Ro)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        // Case 1: head node matches
        if (temp->rollNo == Ro)
        {
            DeleteAtStart();
            return;
        }

        // Case 2: search in rest of list
        Node *temp2 = NULL;
        while (temp != NULL && temp->rollNo != Ro)
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        { // found
            temp2->next = temp->next;
            delete temp;
            cout << "Deleted roll " << Ro << endl;
        }
        else
        {
            cout << "Roll " << Ro << " not found" << endl;
        }
    }

    void SearchAndUpdate(int Ro, string newName, int newRollNo, int newMarks)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "list is empty" << endl;
            return;
        }
        bool found = false;
        while (temp != NULL)
        {
            if (temp->rollNo == Ro)
            {
                temp->name = newName;
                temp->rollNo = newRollNo;
                temp->Marks = newMarks;
                cout<<"Record update for roll no "<< Ro<< endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Roll " << Ro << " not found" << endl;
        }
    }

  void reverse(){
    Node *current=head;
    Node *prev=NULL;
    Node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
  }

  void removeduplicates(){
     Node * temp=head;
      if(temp==NULL){
        cout<<"List is empty"<<endl;
        return;
      }
      Node *current=head;
      while(current->next!=NULL){
        if(current->rollNo==current->next->rollNo){
            Node* duplicate=current->next;
            current->next=duplicate->next;
            delete duplicate;
        }else{
            current=current->next;
        }
      }
  }

  void middleNode(bool getSecond){
    Node *slow=head;
    Node *fast;
            if(getSecond){
              fast=head;
            }
            else{
              fast=head->next;
            }
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle Node is: "<<endl;
    cout<<"Name: "<<slow->name<<endl;
    cout<<"Roll: "<<slow->rollNo<<endl;
    cout<<"Marks: "<<slow->Marks<<endl;

  }
    };

    int main()
    {
        SingleList l;
        l.InsertAtStart("Talha", 126, 76);
        l.InsertAtStart("Ahmad", 149, 87);
        l.InsertAtStart("Saqib", 109, 77);
        l.InsertAtPosition("Ali", 122, 45, 3);
        l.InsertAtLast("Zafar", 139, 79);
        l.InsertAtLast("Zafar", 139, 79);
        l.display();
        cout << endl
             << endl
             << endl
             << endl;
        // l.DeleteAtStart();
        // l.DeleteAtEnd();
        // l.DeleteAtPosition(2);
        // l.SearchAndDelete(122);
        // l.display();
        // cout<<endl<<endl;
        // l.SearchAndUpdate(149, "Ahmad Naveed", 149, 90);
        // cout<<endl<<endl;
        // l.display();
        // cout<<endl<<endl;
        // l.reverse();
        // cout<<endl<<endl;
        // l.display();
        // l.removeduplicates();
        // cout<<endl<<endl;
        // l.display();
        cout<<endl<<endl<<endl<<endl;
        l.middleNode(true);
        return 0;
    }