#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> preprocess(const vector<int>& visitors) {
    int n = visitors.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = visitors[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + visitors[i];
    }
    return prefixSum;
}

int querySum(const vector<int>& prefixSum, int start, int end) {
    if (start == 0) {
        return prefixSum[end];
    }
    return prefixSum[end] - prefixSum[start - 1];
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int number;
    vector<int> visitors;

    while (iss >> number) {
        if (!iss.fail()) {
            visitors.push_back(number);
        } else {
            cout << "Input is not in correct format or missing\n";
            return 0;
        }
    }

    vector<int> prefixSum = preprocess(visitors);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int start, end;
        cin >> start >> end;
        cout << querySum(prefixSum, start, end) << endl;
    }

    return 0;
}
