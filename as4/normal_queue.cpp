#include<iostream>
using namespace std;

class Queue{
  int size;
  int start = -1;
  int end = -1;
  int *arr;

  public:
  Queue(int size){
    this->size = size;
    arr = new int[size];
  }

  void Enqueue(int input){
    if (start+1 == size){
      cout << "Error: The Queue is filled.";
        return;
    }
    arr[++start] = input;
  }

  int Dequeue(){
    if (start < end){
      cout << "Queue is empty";
    }
  }

  ~Queue(){
    delete[] arr;
  }
};

int main(){
  Queue q(2);
  q.Enqueue(10);
  q.Enqueue(20);
  cout << q.Dequeue() <<endl;
}
