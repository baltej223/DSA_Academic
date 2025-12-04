#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node* left=NULL;
  Node* right=NULL;
};

Node* CreateBSTfromArray(vector<int> v){
  if (v.size() == 0){
    throw "array can't be empty";
  }
  Node *root = new Node{v[0]};

  for (int i=1; i<v.size(); i++){
   Node* current_level = root;


   while (true){
    if (v[i] < current_level->data){ 
     if (current_level->left != NULL){
         current_level = current_level->left;
       }
       else {
         current_level->left =  new Node{data:v[i]};
         break;
       }
     } 
     else if (v[i]> current_level->data){
       if (current_level->right != NULL){
         current_level = current_level->right;
       }
       else {
         current_level->right =  new Node{data:v[i]};
         break;
       }
     }
     else{
       // duplicates are ignored
       break;
     } 
   }
  }

  return root;
}

void Inorder(Node *node){
  if (node == NULL){
    return;
  }
  Inorder(node->left);
  cout << node->data << " ";
  Inorder(node->right);
}

void Preorder(Node *node){
  if (node == NULL){
    return;
  }
  cout << node->data << " ";
  Inorder(node->left);
  Inorder(node->right);
}

void Postorder(Node *node){
  if (node == NULL){
    return;
  }
  Inorder(node->left);
  Inorder(node->right);
 cout << node->data << " ";
}



int main(){
  vector<int> v = {21, 42, 43, 75, 21};
  Node *BST = CreateBSTfromArray(v);
  Inorder(BST);

  cout << endl;
  Postorder(BST);
  cout << endl;
  Preorder(BST);
}
