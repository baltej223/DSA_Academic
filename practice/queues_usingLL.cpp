#include "linkedList.cpp"
using namespace std;

class Queue{
    public:
    
    Node* start;
    Node* end;
    int size;

    Queue(){
        size = 0;
        start=NULL;
        end = NULL;
    }

    void push(int val){
        size++;
        Node* temp = new Node(val);
        if (start == NULL && end == NULL){
            // On starting
            start = temp;
            end = temp;            
        }
        else{
            end->next = temp;
        }
    }

    void pop(){
        size--;
        Node* temp = start;
        start = start->next;
        delete temp;
    }

    void top(){
        cout << start->data << " ";
    }
};

int main(){
Queue q1;

q1.push(213);
q1.push(242);
q1.top();
q1.pop();
q1.top();
}