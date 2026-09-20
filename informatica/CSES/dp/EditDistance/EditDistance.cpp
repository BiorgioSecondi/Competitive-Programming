#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pqi = priority_queue<int>;
using pqll = priority_queue<ll>;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
ifstream cin("input.txt");
ofstream cout("output.txt");
#endif

int main(){
    string A,B;
    ::cin >> A;
    ::cin >> B;
    ll n = A.size();
    ll m = B.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < m ; j++){
    //         ::cout << dp[i][j] << " ";
    //     }
    //     ::cout << endl;
    // }
    // ::cout << "--------------------------------------" << endl;

    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = i;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = j;
    }

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < m ; j++){
    //         ::cout << dp[i][j] << " ";
    //     }
    //     ::cout << endl;
    // }
    // ::cout << "--------------------------------------" << endl;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dp[i][j] = min( dp[i-1][j-1] + (A[i-1] != B[j-1]) , min( 1 + dp[i-1][j] , 1 + dp[i][j-1] ));
        }
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            ::cout << dp[i][j] << " ";
        }
        ::cout << endl;
    }
    ::cout << "--------------------------------------" << endl;

    ::cout << dp[n][m] << endl;
    
    return 0;
}