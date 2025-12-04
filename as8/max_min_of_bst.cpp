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

int max_iterative(Node* BST){
  Node* current_level = BST;
  while (true){
    if (current_level->right != NULL){
      current_level = current_level->right;
    }
    else{ 
      return current_level->data;
    }
  }
}

int min_iterative(Node* BST){
  Node* current_level = BST;
  while (true){
    if (current_level->left != NULL){
      current_level = current_level->left;
    }
    else {
      return current_level->data;
    }
  }
}

int main(){
  vector<int> v = {21,43, 64, 75,232,643, 3, 53, 213, 21};
  Node *BST = CreateBSTfromArray(v);

  cout << "Min is " << min_iterative(BST) << endl;
 cout << "Max is " << max_iterative(BST) << endl;
}
