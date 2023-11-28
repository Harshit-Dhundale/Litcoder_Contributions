#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class CustomStack {
    string text;
    stack<pair<int, string>> history;  // Stores the type of operation and the affected text

public:
    void insert(const string& value) {
        history.push({1, value});
        text += value;
    }

    void deleteChars(int value) {
        if (value > text.length()) value = text.length();
        string deleted = text.substr(text.length() - value, value);
        history.push({2, deleted});
        text.erase(text.length() - value, value);
    }

    char get(int value) {
        if (value < 1 || value > text.length()) return '\0';
        return text[value - 1];
    }

    void undo() {
        if (history.empty()) return;
        auto action = history.top();
        history.pop();

        if (action.first == 1) {
            // Undo insert
            text.erase(text.length() - action.second.length(), action.second.length());
        } else if (action.first == 2) {
            // Undo delete
            text += action.second;
        }
    }
};

vector<string> processCommands(const vector<string>& commands) {
    CustomStack editor;
    vector<string> output;

    for (const auto& cmd : commands) {
        istringstream iss(cmd);
        int commandType;
        string arg;
        iss >> commandType;
        
        switch (commandType) {
            case 1: {
                iss >> arg;
                editor.insert(arg);
                break;
            }
            case 2: {
                int value;
                iss >> value;
                editor.deleteChars(value);
                break;
            }
            case 3: {
                int value;
                iss >> value;
                char result = editor.get(value);
                if (result != '\0') output.push_back(string(1, result));
                break;
            }
            case 4:
                editor.undo();
                break;
        }
    }

    return output;
}

int main() {
    vector<string> commands = {"1 abc", "3 3", "2 2", "3 1"};  // Example input
    vector<string> output = processCommands(commands);

    for (const auto& out : output) {
        cout << out << endl;
    }

    return 0;
}
