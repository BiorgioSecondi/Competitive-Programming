#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<long long> taglia(int N, int M, int Q, vector<vector<long long>> A, vector<long long> K);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M, Q; cin >> N >> M >> Q;
    vector A(N, vector<long long>(M, 0));
    vector<long long> K(Q, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> K[i];
    }

    auto R = taglia(N, M, Q, A, K);

    for (long long x : R) cout << x << ' ';
    cout << endl;

    return 0;
}
