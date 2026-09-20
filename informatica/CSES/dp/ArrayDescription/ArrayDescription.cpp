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
    #define debug(x) ::cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

const int MODULO = 1e9 + 7;

int main(){
    ll n,m;
    ::cin >> n >> m ;
    vector<int> A(n);
    for(auto &x : A) ::cin >> x;

    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i = 0 ; i < n ; i++){
        if(A[i] == 0){
            for(int j = 0 ; j < m ; j++){
                dp[i][j] = 1;
            }
        }
        else{
            dp[i][A[i]-1] = 1;
        }
    }
    /*
    for(int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            ::cout << dp[i][j] << " ";
        }
        ::cout << endl;
    }

    ::cout << "----------------------------------------------" << endl;
    */

    for(int i = 1; i < n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(j == 0){
                dp[i][j] *= dp[i-1][j]+dp[i-1][j+1];
                dp[i][j] %= MODULO;
            }
            else if(j == m - 1){
                dp[i][j] *= dp[i-1][j]+dp[i-1][j-1];
                dp[i][j] %= MODULO;
            }
            else{
                int temp = dp[i-1][j]+dp[i-1][j+1];
                temp %= MODULO;
                dp[i][j] *= temp + dp[i-1][j-1];
                dp[i][j] %= MODULO;
            }
        }
    }

    /*
    for(int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            ::cout << dp[i][j] << " ";
        }
        ::cout << endl;
    }
    */

    ll ans = 0;
    for(int j = 0 ; j < m ; j++){
        ans += dp[n-1][j];
        ans %= MODULO;
    }
    
    ::cout << ans << endl;

    return 0;
}