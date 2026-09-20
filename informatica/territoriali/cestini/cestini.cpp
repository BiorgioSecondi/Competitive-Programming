#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, M, Q;
    cin >> N >> M >> Q;

    string S;
    cin >> S;

    vector<vector<char>> cesto(M);
    for (int i=0;i<N;i++){
        cesto[0].push_back(S[i]);
    }

    string risposta;

    for (int i = 0; i < Q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 's') {
            cesto[b].push_back(*(cesto[a].end()-1));
            cesto[a].pop_back();

        } else {
            risposta.push_back(cesto[a][b]);
        }
    }


    cout << "Case #" << t << ": " << risposta << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}