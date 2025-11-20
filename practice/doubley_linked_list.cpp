#include<iostream>
#include<vector>

using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int data,Node* next=NULL, Node* prev=NULL){
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
};

Node * CreateALinkedListFromArray(vector<int> arr){
  int size = arr.size();
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for (int i=1; i<size; i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    temp->prev=mover;
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



int main(){
  vector<int> arr = {1,2,3,53,523,2};
  Node* head = new Node(0); 

PrintLL(CreateALinkedListFromArray(arr));

 delete[] head;
}