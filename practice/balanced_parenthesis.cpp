#include "stack.cpp"

using namespace std;

int main(){
stack s(10);

string parenthesis = "{{}[]()()}";

char opening[] = {'(', '[', '{'};
char closing[] = {')', ']', '}'};

bool inValid = false;
for (int i =0; i<parenthesis.size(); i++){
    char bracket = parenthesis[i];
    cout << "For bracket " << bracket << endl;

    if (bracket == '[' || bracket == '(' || bracket == '{'){
        cout << "pushed\n";
        s.push(bracket);
    }
    else if (bracket == ']' || bracket == ')' || bracket == '}'){
        cout << s.top() << endl;
        if (s.top() == bracket){
            cout << "popped\n";
            s.pop();
        }
        else{
            inValid = true;
            break;
        }
    }
}

if (inValid){
    cout << "Invalid";
}
else {
    cout << "Valid";
}
}