#include <iostream>
#include <vector>

using namespace std;

int findParent(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main() {
    int N, M, Q;
    bool firstCase = true;
    while (cin >> N >> M >> Q) {
        if (!firstCase) {
            cout << endl;
        }
        firstCase = false;

        vector<int> parent(N + 1);
        vector<int> rank(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < M; ++i) {
            int X, Y;
            cin >> X >> Y;
            unionSets(X, Y, parent, rank);
        }

        for (int i = 0; i < Q; ++i) {
            int A, B;
            cin >> A >> B;
            if (findParent(A, parent) == findParent(B, parent)) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }

    return 0;
}