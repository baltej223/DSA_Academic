#include<iostream>
using namespace std;

struct stack{
    int size;
    char *arr;

    int _top = -1;
    stack(int size){
        this->size = size;
        arr = new char[size];
    }

    void push(char value){
        _top++;
        arr[_top] = value;
    }

    char top(){
        // cout << "Top is " << arr[_top] << endl;
        return arr[_top];
    }
    
    void pop(){
        _top--;
    }

};

// int main(){
// stack s(10);
// s.push(2);
// s.push(3);
// s.top();
// s.top();
// s.pop();
// s.top();

// }