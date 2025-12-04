#include<iostream>

using namespace std;
// balanced parenthesis

template <typename T>
class Stack{
  // The raw memory pointer one.
  T *arr;
  int top = -1;
  int size;

  public:
  Stack(int size){ 
    this->size = size; 
    arr = new T[size];
  }

  void push(T value){
    if (top+1 == size){
      cout << "Can't add more element that size in stack \n";
      exit(1);
      // return;
    }
    arr[++top] = value;
  }

  T pop(){
    if (top == -1){
      cout << "Can't pop when there is nothing in stack";
    }
    return arr[top--];
  }

  T  get(){
    return arr[top];
  }

  bool isEmpty(){
    return top+1 == 0 ? true : false;
  }

  ~Stack(){
    delete[] arr;
  }
};


int main(){
  string brackets = "{{}}}";
  int size = brackets.length();
  Stack<char> s(size);

  string start = "{[(";
  string end = "}])";

  for (int i=0; i<brackets.length(); i++){
    char current_bracker = brackets[i];
    if (current_bracker == '{' || current_bracker == '(' || current_bracker==']')
      s.push(current_bracker);

    if (current_bracker == '}' || current_bracker == ')' || current_bracker == ']')
      s.pop();
  }
  if (s.isEmpty()){
    cout << "No problem";
  } 
  else {
    cout << "Problem";
  }
}
