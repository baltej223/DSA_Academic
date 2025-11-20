#include<iostream>
#include<vector>

using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data,Node* next=NULL){
    this->data = data;
    this->next = next;
  }
};

Node* CreateALinkedListFromArray(vector<int> arr){
  int size = arr.size();
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for (int i=1; i<size; i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

void PrintLL(Node* head){
  Node* current = head;
  while (current!=NULL){
    cout << current->data << " ";
    current = current->next;
  } 
}

Node* InsertAtBeigning(Node* head, int value){
    Node* temp = new Node(value);
    temp->next = head;
    return temp;
}

Node* InsertAtEnd(Node* head, int value){
  Node* current = head;
  while (current!=NULL){
    current=current->next;
  }
  Node* temp = new Node(value);
  current->next = temp;
  return head;
}



// int main(){
//   vector<int> arr = {1,2,3,53,523,2};
//   Node* head = new Node(0); 

// PrintLL(CreateALinkedListFromArray(arr));
// }