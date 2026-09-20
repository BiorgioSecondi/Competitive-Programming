#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#define _ << " " <<

const int MAXN = 1000;
const int MAXM = 1000;
int dp[MAXN][MAXM];

int solve() {
    int N, M;
    cin >> N >> M;
    

    int risposta = 0;  // memorizza qui la risposta
    vector<int> V(N), G(M);

    for (int i=0; i<N; i++) {
        cin >> V[i];
    }
    for (int i=0; i<M; i++) {
        cin >> G[i];
    }

    

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==0 and j==0) {dp[0][0] = V[0]<G[0]; continue;}
            if(i==0){
                if(dp[i][j-1]==1) dp[i][j]=1;
                else dp[i][j]=V[i]<G[j];
                continue;
            }
            if(j==0){
                if(dp[i-1][j]==1) dp[i][j]=1;
                else dp[i][j]=V[i]<G[j];
                continue;
            }
            int mirabelli= V[i]<G[j] ? dp[i-1][j-1]+1 : 0;
            dp[i][j]=max( max( dp[i][j-1] , dp[i-1][j] ) , mirabelli );
        }
    }

    risposta=N+dp[N-1][M-1];

    return risposta;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}