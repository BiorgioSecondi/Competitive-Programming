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

const ll MAXN = 1e6;
const ll MODULO = 1e9 + 7;

int main(){
    vector<vector<ll>> dp(MAXN+1,vector<ll>(2,0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1 ; i <= MAXN ; i++){
        dp[i][0] = 2*dp[i-1][0];
        dp[i][1] = dp[i-1][0];
        dp[i][0] += dp[i-1][1];
        dp[i][0] %= MODULO;
        dp[i][1] += 4*dp[i-1][1];
        dp[i][1] %= MODULO;
    }
    ll t;
    ::cin >> t;
    while(t--){
        ll input;
        ::cin >> input;
        ::cout << (dp[input-1][1]+dp[input-1][0])%MODULO << endl;
    }
    return 0;
}