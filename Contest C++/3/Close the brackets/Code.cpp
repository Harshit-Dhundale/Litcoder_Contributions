#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isBalanced(const string& s) {
    stack<char> stk;

    for (char ch : s) {
        switch (ch) {
            case '(': 
            case '{': 
            case '[':
                stk.push(ch);
                break;
            case ')': 
                if (stk.empty() || stk.top() != '(') return false;
                stk.pop();
                break;
            case '}': 
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop();
                break;
            case ']': 
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop();
                break;
        }
    }

    return stk.empty();
}

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    string brackets;

    while (getline(iss, brackets, ',')) {
        cout << (isBalanced(brackets) ? "YES" : "NO") << endl;
    }

    return 0;
}
