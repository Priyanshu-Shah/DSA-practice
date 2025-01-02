#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()){
                cout << position+1 << endl;
                return 0;
            }
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if(top.Matchc(next) == false){
                cout << position+1 << endl;
                return 0;
            }
            // Process closing bracket, write your code here
        }

    }

    if(opening_brackets_stack.empty() == false){
        Bracket unmatched = opening_brackets_stack.top();
        cout << unmatched.position+1 << endl;
    }
    else{
        cout << "Success" << endl;
    }
    return 0;
}
