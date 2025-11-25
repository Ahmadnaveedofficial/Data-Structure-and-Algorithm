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
};

 class BST{
    public:
      Node* root;
      Node*insert(Node* root ,int data){
        if(root==NULL){
            Node *n=new Node(data);
            return n;
        }else if (data<root->data)
        {
            root->left=insert (root->left,data);
        }else if (data>root->data){
             root->right=insert (root->right,data);
        }
           return root;
      }
      void display(Node* root){
        if(root==NULL){
            return;
        }
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
      }

  };

  int main(){
     Node* root = NULL;
        BST tree;
        root = tree.insert(root, 50);
        tree.insert(root, 30);
        tree.insert(root, 20);
        tree.insert(root, 40);
        tree.insert(root, 70);
        tree.insert(root, 60);
        tree.insert(root, 80);
        tree.display(root);

        return 0;


  }

  