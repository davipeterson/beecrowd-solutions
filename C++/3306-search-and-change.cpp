#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int range_gcd(const vector<int>& vec, int l, int r) {
    int result = vec[l];
    for (int i = l + 1; i <= r; ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) break;
    }
    return result;
}

int main() {
    int N, Q;
    while (cin >> N >> Q) {
        vector<int> vec(N);
        for (int i = 0; i < N; ++i) {
            cin >> vec[i];
        }

        for (int i = 0; i < Q; ++i) {
            int type, A, B, V;
            cin >> type >> A >> B;
            if (type == 1) {
                cin >> V;
                for (int j = A - 1; j <= B - 1; ++j) {
                    vec[j] += V;
                }
            } else if (type == 2) {
                cout << range_gcd(vec, A - 1, B - 1) << endl;
            }
        }
    }
    return 0;
}