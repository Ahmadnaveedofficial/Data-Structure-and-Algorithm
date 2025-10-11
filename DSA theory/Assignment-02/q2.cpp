#include <iostream>
using namespace std;

class Employee{
    public:
    int id,age,salary;
    string name;
    Employee* next;
    Employee(int id,string name,int age,int salary){
        this->id=id;
        this->name=name;
        this->age=age;
        this->salary=salary;
       next=NULL;
    }
};

class Linklist{
   Employee* head;
   public:
   Linklist(){
    head=NULL;
   }
   void maximumSalary(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Employee* max=head;
    Employee*temp=head;
    while(temp!=NULL){
        if(temp->salary>max->salary){
            max=temp;
        }
        temp=temp->next;
    }
    cout<<"Employee with max salary"<<endl;
    cout<<"Employee Name: "<<max->name<<endl;
    cout<<"Employee ID: "<<max->id<<endl;
    cout<<"Employee Age: "<<max->age<<endl;
    cout<<"Employee Salary: "<<max->salary<<endl;
   }

   void displayAlphabet(){
    char ch='a';
    while(ch<='z'){
         Employee*temp=head;
        while(temp!=NULL){
            if(tolower(temp->name[0])==ch){
                 cout<<"Employee Name: "<<temp->name<<endl;
                 cout<<"Employee ID: "<<temp->id<<endl;
                 cout<<"Employee Age: "<<temp->age<<endl;
                 cout<<"Employee Salary: "<<temp->salary<<endl<<endl;
            }
            temp=temp->next;
        }
        ch++;
    }
   }


   void insertAlphabet(int id,string name,int age,int salary ){
    Employee* temp=head;
    Employee* newEmployee=new Employee(id,name,age,salary);
    if(head==NULL || tolower(head->name[0])<tolower(newEmployee->name[0]) ){
        newEmployee->next=head;
        head=newEmployee;
        return;
    }
    while(temp!=NULL && tolower(temp->name[0]) < tolower(newEmployee->name[0])){
          temp=temp->next;
          
    }
       newEmployee->next=temp->next;
          temp->next=newEmployee;
   }



   void Delete(int id){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Employee* temp=head;
    if(head->id==id){
        Employee* temp2=head;
        head=head->next;
        delete temp2;
        temp2=NULL;
         cout<<"Employee deleted successfully!" << endl;
         return;
    }else{
        Employee* temp3=NULL;
        while(temp!=NULL && temp->id!=id){ 
             temp3=temp;
             temp=temp->next;
           }
           if(temp!=NULL){
            temp3->next=temp->next;
            delete temp;
           }
   }
   return;
}
void update(int id){
      if(head!=NULL){
        Employee* temp=head;
        while(temp!=NULL && temp->id!=id){
            temp=temp->next;
        }
      cout<<"Updating employee with ID "<<id<<endl;
      cout<<"Current Name: "<<temp->name<< ", Age: "<<temp->age<<", Salary: "<<temp->salary<<endl;
      cout<<"Enter new name: ";
      cin.ignore();
      getline(cin,temp->name);
      cout<<"Enter new age: ";
      cin>>temp->age;
      cout<<"enter new salary: ";
      cin>>temp->salary;
     cout<<"Employee updated successfully!"<<endl;
        
      }
}
 void search(string name){
    Employee*temp=head;
    if(head!=NULL){
        while(temp!=NULL && temp->name!=name){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Employee not found (:)"<<endl;
        }else{
                cout<<"Employee Name: "<<temp->name<<endl;
                 cout<<"Employee ID: "<<temp->id<<endl;
                 cout<<"Employee Age: "<<temp->age<<endl;
                 cout<<"Employee Salary: "<<temp->salary<<endl<<endl;
        }
    }
 }
};

int main(){
    Linklist li;
    li.insertAlphabet(149,"Ahmad Naveed",20,50000);
    li.insertAlphabet(150,"Mohsin Naveed",22,52322);
    li.insertAlphabet(148,"Ahsan Naveed",24,343233);
    li.insertAlphabet(142,"Naveed Ahmad",58,233);
    cout<<"All Employees (Alphabetical Order):"<<endl;
    li.displayAlphabet();
    li.maximumSalary();
    cout<<endl;
    cout<<"Searching Employee with name 'Ahmad Naveed'"<<endl;
    li.search("Ahmad Naveed");
    cout<<endl;
    li.update(150);
    cout<<endl;
    cout<<"Deleting Employee with ID 149"<<endl;
    li.Delete(149);
    cout<<endl;
    cout<<"All Employees (Alphabetical Order):"<<endl;
    li.displayAlphabet();
}