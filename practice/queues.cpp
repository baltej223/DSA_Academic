#include<iostream>
using namespace std;

class Queue{
    public:
    int current_size;
    int* arr;
    
    int start = -1;
    int end = -1;

    int size;
    Queue(int size){
        arr = new int[size];
        this->size = size;
        current_size = 0;
    }

    void push(int value){
        if (current_size == size){
            cout << "Overflow";
            return;  // also good to return here
        }
        if (current_size == 0){
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % size;
        }
        arr[end] = value;
        current_size++;
    }

    void pop() {
        if (current_size == 0) {
            cout << "The Queue is empty\n";
            return;  // must return here to stop further execution
        }
        if (current_size == 1) {
            start = -1;
            end = -1;
            current_size = 0;  // reset current_size to zero here!
            return;
        }
        else {
            start = (start + 1) % size;
            current_size--;
        }
    }

    int top(){
        cout << "The top of queue is " << arr[start] << endl;
        return arr[start];
    }
    
};

int main(){
    Queue q1(12);

    q1.push(213);
    q1.push(42);
    q1.top();
    q1.push(213);
    q1.push(42);
    q1.top();
    q1.push(213);
    q1.push(42);
    q1.top();
    q1.pop();
    q1.top();

}