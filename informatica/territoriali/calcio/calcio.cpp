#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 7000
#define MAXM 7000
#define ll long long

ll prefix[MAXN+1][MAXM+1];

void solve(int t) {
    int N, M, K, A, B;
    cin >> N >> M >> K >> A >> B;

    vector<int> X(K), Y(K);
    for (int i = 0; i < K; i++) {
        cin >> X[i] >> Y[i];
    }

    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXM; j++){
            prefix[i][j]=0;
        }
    }

    for(int i=0;i<K;i++){
        prefix[X[i]+1][Y[i]+1] += 1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            prefix[i][j]=prefix[i][j]+(ll)prefix[i-1][j]+(ll)prefix[i][j-1]-(ll)prefix[i-1][j-1];
        }
    }

    ll risposta = INT64_MAX;

    for(int i = A; i <= N ; i++ ){
        for(int j = B; j<= M ; j++){
            risposta = min(risposta,prefix[i][j]-(ll)prefix[i-A][j]-(ll)prefix[i][j-B]+(ll)prefix[i-A][j-B]);
        }
    }
    
    cout << "Case #" << t << ": " << risposta << "\n";
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