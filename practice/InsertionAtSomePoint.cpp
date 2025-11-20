#include "linkedList.cpp"
using namespace std;

int main(){
    LinkedList l;
    vector<int> arr = {1,2,42,52,53,252,25};
    l.createFromArray(arr);
    l.InsertAtPosition(3, 5);
    
}