#include<iostream>
#include<vector>

using namespace std;

// So We have some options for writting Stack class, 
// 1. Option one id in which I can write everything from pure basics, no dependencies. Raw memory management.
// 2. We can use a template to get size of the array at compile time, and then can allocate that much on memory
// 3. We can use a vector, and can abrtract the Stack on it.

class Stack{
  // The raw memory pointer one.
  int *arr;
  int top = -1;
  int size;

  public:
  Stack(int size){ 
    this->size = size; 
    arr = new int[size];
  }

  void push(int value){
    if (top+1 == size){
      cout << "Can't add more element that size in stack \n";
      exit(1);
      // return;
    }
    arr[++top] = value;
  }

  void pop(){
    if (top == -1){
      cout << "Can't pop when there is nothing in stack";
    }
    top--;
  }

  int  get(){
    return arr[top];
  }

  ~Stack(){
    delete[] arr;
  }
};

template <typename T>
class Stack_Vector{
  // I don't want to write this one.
  //
  int size;
  int top = -1;
  vector<T> v;
  
  public:
  Stack_Vector(int size){
    this->size = size;
  }

  void push(int value){
    if (top +1 == size){
      cout << "Error: Stack is filled." << endl;
      exit(1);
    }
    v.push_back(value);
    top++;
  }

  void pop(){
    if (top == -1) 
      cout << "Stack is already empty." <<endl;
    v.pop_back();
    top--;
  }

  void get(){
    return v[top];
  }
};

template <int SIZE>
class Stack_Template{
  int arr[SIZE];
  int top = -1;

  public:
  void push(int value){
    if (top+1 == SIZE){
      cout << "Can't add more element that size in stack \n";
      exit(1);
      // return;
    }
    arr[++top] = value;
  }

  void pop(){
    if (top == -1){
      cout << "Can't pop when there is nothing in stack";
    }
    top--;
  }

  int get(){
    return arr[top];
  }
};



int main(){
  Stack s(10);
  s.push(10);
  s.push(9);
  cout << s.get() <<endl;
  s.pop();
  cout << s.get() << endl;

  Stack_Template<10> s1;
  s1.push(10);
  s1.pop();
  s1.push(9);
  cout << s1.get() << endl;

  Stack_Vector<int> sv(0);
  sv.push(10);
  return 0;
}
