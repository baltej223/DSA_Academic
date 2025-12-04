#include<iostream>
#include<vector>

using namespace std;

struct Node{
  int data;
  Node* left = NULL;
  Node* right = NULL;
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

Node* InsertAnElement(Node* BST, int element){
  Node * current_level = BST; 
  while (true){
    if (element < current_level->data){ 
     if (current_level->left != NULL){
         current_level = current_level->left;
       }
       else {
         current_level->left =  new Node{data:element};
         break;
       }
     } 
     else if (element > current_level->data){
       if (current_level->right != NULL){
         current_level = current_level->right;
       }
       else {
         current_level->right =  new Node{data:element};
         break;
       }
     }
     else{
       break;
     } 
   }
return BST;
}

int main(){

}
