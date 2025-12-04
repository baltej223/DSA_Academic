#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Stack_Vector{
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

   T pop(){
    if (top == -1) {
      cout << "Stack is already empty." <<endl;
    exit(1);
    }
      v.pop_back();
    top--;
    return this->get();
  }

  T get(){
    return v[top];
  }
};


 
int main(){
  string input = "DataStructures";  

  int input_length  = input.length();
  Stack_Vector<char> s(input_length);

  for (char x : input){
    s.push(x);
  }

  for (int i=1; i<input_length; i++){
    cout << s.pop();
  }
}
