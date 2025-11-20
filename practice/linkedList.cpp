#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next=nullptr){
        this->data = data;
        this->next = next;
    }
};


class LinkedList{
    public:

    Node* head;

    Node* createFromArray(vector<int> arr){
        Node* head = new Node(arr[0]);
        Node* mover = head;
        this->head = head;
        
        for (int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

    void printLL(){
        Node* current = head;
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
    }

    void InsertAtPosition(int value, int position){
        Node* current = head;
        int counter=1;
        while (current != nullptr || counter<position){
            current = current->next;
            counter++;
        }
        // Now current is the Node one behind the actual node.
        Node* temp = current;
        current=current->next;
        Node* a = new Node(value);
        temp->next = a;
        a->next = current;
    }
};

// int main(){
//     LinkedList l;

//     vector<int> arr = {1,2,4,5,46,4,35,35,32,2};
//     l.createFromArray(arr);
//     l.printLL();
// }
