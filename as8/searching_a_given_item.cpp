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


void  Search(Node *node, int item){
  if (node == NULL){
    return;
  }

  if (item < node->data){
    if (node->left != NULL){
      Search(node->left, item);
    }
    else {
      cout << "Not found";
    }
  }
  else if (item > node->data){
    if (node->right != NULL){
      Search(node->right, item);
    }
    else {
      cout << "Not found";
    }
  }
  else {
    cout << "Found";
  }
}

void Search_iterative(Node* BST,int item){
  Node* current_level = BST;
 
  while (true){
    if (item<current_level->data){
      if (current_level->left != NULL){
        current_level = current_level->left;
      }
      else {
        cout << "Not found";
        break;
      }
    }
    else if (item>current_level->data){
      if (current_level->right != NULL){
        current_level = current_level->right;
      }
      else {
        cout << "Not found";
        break;
      }
    }

    else{
      cout << "found";
    }
  }
}

int main(){
  vector<int> v = {21,43, 64, 75,232,643, 3, 53, 213, 21};
  Node *BST = CreateBSTfromArray(v);

  Search(BST,75);
  cout << endl;
  Search_iterative(BST, 54);

}
