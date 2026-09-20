#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int j = 0; j < m; ++j) cin >> B[j];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[n][m];
    cout << len << '\n';

    vector<int> seq;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(A[i-1] == B[j-1]){ seq.push_back(A[i-1]); --i; --j; }
        else if(dp[i-1][j] >= dp[i][j-1]) --i;
        else --j;
    }
    reverse(seq.begin(), seq.end());
    for(size_t k = 0; k < seq.size(); ++k){
        if(k) cout << ' ';
        cout << seq[k];
    }
    cout << '\n';

    return 0;
}