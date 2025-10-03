struct node{
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
node* head=nullptr;
node* newnode;
void createlist(){
    newnode=new node(10);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;   
    }
}
insertende{
    newnode=new node(20);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;   
    }
}


























// double linked list
void insertAtStart(int data){
    if(head==NULL){
        return;
    }
    Node* n=new Node(data);
    n->next=head;
    head->prev=n;
    head=n;
}

void insertAtEnd(int data){
    if(head==NULL){
        return;
    }
    Node* n=new Node(data);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

