#include<iostream>
using namespace std;

class Circular_Queue{
  int size;
  int *arr;
  int start = -1;
  int end = -1;

  public:
  Circular_Queue(int size){
    this->size = size;
    arr = new int[size];
  }

  void Enqueue(int value){
    start = (start+1)%size;
    arr[start] = value;
  }

  void Dequeue(){
    end = (end+1)%size; 
  }

  int get(){
    return arr[start];
  }
};

int main(){
  Circular_Queue q(2);
  q.Enqueue(10);
  q.Enqueue(9);
  q.Dequeue();
  q.Enqueue(9);
  q.Enqueue(91);
  q.Enqueue(9);
  q.Enqueue(9);
  cout << q.get() << endl;
}
