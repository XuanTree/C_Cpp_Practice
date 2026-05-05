#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isMatchingPair(char opening, char closing){
    return  (opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}');
}
bool isBalanced(string expression){
    stack<char> s;
    for (char c : expression){
        if (c == '(' || c == '[' || c == '{'){
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}'){
            if (s.empty()){
                return false;
            }
            char top = s.top();
            s.pop();
            if (!isMatchingPair(top, c)){
                return false;
            }
        }
    }
    return s.empty();
}
int main(){
    string input;
    cin >> input;
    if (isBalanced(input)){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}