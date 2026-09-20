#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

vector<int> ranking(int N, int T, vector<int> X, vector<int> V, vector<int> P);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove these two lines in interactive problems.

    int N, T;
    assert(cin >> N);
    assert(cin >> T);

    vector<int> X(N), V(N), P(N);

    for (int& x : X)
        assert(cin >> x);
    for (int& x : V)
        assert(cin >> x);
    for (int& x : P)
        assert(cin >> x);

    vector<int> risposta = ranking(N, T, X, V, P);

    for (int x: risposta)
        cout << x << ' ';
    cout << endl;
}
