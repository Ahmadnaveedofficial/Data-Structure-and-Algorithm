  #include <iostream>
  using namespace std;

  class Node{
      public:
    int data;
    Node* left,*right;
    Node(int data){
      this->data=data;
      left=right=NULL;
    }

    Node *insert(Node *root,int data){
      if(root==NULL){
        Node *newNode=new Node(data);
        return newNode;
      }else if(data<root->data){
        root->left=insert(root->left,data);
      }else if(data>root->data){
        root->right=insert(root->right,data);
      }
        return root;
    }
    
  Node* deleteNode(Node* root, int data) {
      if (root == NULL)
          return root;
      if (data < root->data) {
          root->left = deleteNode(root->left, data);
      }
      else if (data > root->data) {
          root->right = deleteNode(root->right, data);
      }
      else {
          // Case 1: No child
          if (root->left == NULL && root->right == NULL) {
              delete root;
              return NULL;
          }
          // Case 2: One child
          else if (root->left == NULL) {
              Node* temp = root->right;
              delete root;
              return temp;
          }
          else if (root->right == NULL) {
              Node* temp = root->left;
              delete root;
              return temp;
          }
          // Case 3: Two children 
          Node* pred = root->left;
          while (pred->right != NULL){
              pred = pred->right;
          }
          root->data = pred->data;                                                         
          root->left = deleteNode(root->left, pred->data);                                     
      }

      return root;
  }

  bool search(Node*root,int key){
    if(root==NULL){
      return false;
    }
    if(root->data==key){
    return true;
    }
    if(key<root->data){
      return search(root->left,key);
    }else{
      return search(root->right,key);
    }
  }

  Node* findMini(Node * root){
    while(root->left!=NULL){
      root=root->left;
    }
    return root;
  }

  Node *findMax(Node * root){
    while(root->right!=NULL){
      root=root->right;
    }
    return root;
  }

  // preoder display

  void preOrder(Node*root){
    if(root==NULL){
      return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
  }

  // postorder display

  void postOrder(Node* root){
      if(root==NULL){
      return;
    }
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";    
  }

  // inorder display

  void inOrder(Node* root){
      if(root==NULL){
      return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
  }

     Node* searchAndUpdate(Node* root,int value,int newValue){
        if(root==NULL){
          return NULL;
        }
        if(!search(root,value)){
          cout<<"Value not found"<<endl;
          return root;
        }
        root=deleteNode(root,value);
        root=insert(root,newValue);
        return root;
     }
     
  };



    int main(){

      Node* root = NULL;
  
      root=root->insert(root,12);
      root=root->insert(root,31);
      root=root->insert(root,21);
      root=root->insert(root,9);
      root=root->insert(root,1);

      cout<<"inOrder :";
      root->inOrder(root);
  cout<<endl;
        cout<<"preOrder :";
      root->preOrder(root);
  cout<<endl;
        cout<<"postOrder :";
      root->postOrder(root);
      cout<<endl;
  cout<<"max node in bst is "<< root->findMax(root)->data<<endl;
  cout<<"mini node in bst is "<< root->findMini(root)->data<<endl;
  cout<<"Search 21 :"<<(root->search(root,21)? "found" :"Not found")<<endl;
    
  root=root->searchAndUpdate(root,21,25);
  cout<<"inOrder after update :";
  root->inOrder(root);
  cout<<endl;


          return 0;


    }

    