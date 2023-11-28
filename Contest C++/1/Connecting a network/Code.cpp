#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    int count;

    UnionFind(int n) : parent(n), count(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            count--;
        }
    }
};

int minOperationsToConnect(int N, vector<vector<int>>& routes) {
    UnionFind uf(N);

    for (const auto& route : routes) {
        uf.unite(route[0], route[1]);
    }

    return uf.count - 1; // Subtracting 1 because we start counting from 0
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> routes(M, vector<int>(2));
    for (int i = 0; i < M; ++i) {
        cin >> routes[i][0] >> routes[i][1];
    }

    int result = minOperationsToConnect(N, routes);
    if (result >= 0) {
        cout << result << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
