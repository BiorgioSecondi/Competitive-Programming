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
 
const int MODULO = 1e9+7;
 
int main(){
    ll n,x;
    ::cin >> n >> x;
    vector<int> coins(n);
    for(auto &c:coins) ::cin >> c;
    
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int i = 0 ; i < n ; i++){               //valori sentinella
        dp[i][0] = 1;
    }
    for(int j = 0 ; j <= x ; j++){
        if(coins[0] + j <= x) dp[0][j+coins[0]] += dp[0][j];
    }
 
 
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j <= x ; j++){
            dp[i][j] += dp[i-1][j];
            if(j-coins[i] >= 0){
                dp[i][j] += dp[i][j-coins[i]];
                dp[i][j] %= MODULO;
            }
        }
    }
    /*
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= x ; j++){
            ::cout << dp[i][j] << " ";
        }
        ::cout << endl;
    }
    */
    ::cout << dp[n-1][x] << endl;
    
    return 0;
}