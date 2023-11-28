#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

// Function to check if a string is a number
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c) && c != '-' && c != '+') {
            return false;
        }
    }
    return true;
}

// Function to find dancing pairs
void findDancingPairs(const vector<int>& heights) {
    if (heights.size() <= 1) {
        cout << "No Valid pairs\n";
        return;
    }

    // Checking if all elements are equal
    bool allEqual = all_of(heights.begin(), heights.end(), [heights](int h) { return h == heights[0]; });
    if (allEqual) {
        cout << "No Valid pairs\n";
        return;
    }

    unordered_map<int, int> heightCount;
    for (int h : heights) {
        heightCount[h]++;
    }

    // Sorting the unique heights
    vector<int> uniqueHeights;
    for (auto& p : heightCount) {
        uniqueHeights.push_back(p.first);
    }
    sort(uniqueHeights.begin(), uniqueHeights.end());

    for (size_t i = 0; i < uniqueHeights.size(); ++i) {
        for (size_t j = i + 1; j < uniqueHeights.size(); ++j) {
            while (heightCount[uniqueHeights[i]] > 0 && heightCount[uniqueHeights[j]] > 0) {
                cout << uniqueHeights[j] << " " << uniqueHeights[i] << endl;
                heightCount[uniqueHeights[i]]--;
                heightCount[uniqueHeights[j]]--;
            }
        }
    }
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string height;
    vector<int> heights;

    while (iss >> height) {
        if (!isNumber(height)) {
            cout << "Input string was not in a correct format\n";
            return 0;
        }
        heights.push_back(stoi(height));
    }

    findDancingPairs(heights);
    return 0;
}
