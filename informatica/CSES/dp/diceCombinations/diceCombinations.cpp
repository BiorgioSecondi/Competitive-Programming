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
    ll n;
    ::cin >> n;
    vector<int> dp(n+10,0);
    dp[0] = 1      ;
    dp[1] = 1      ;
    dp[2] = 2      ;
    dp[3] = 4      ;
    dp[4] = 4+2+1+1;
    dp[5] = dp[4]+dp[3]+dp[2]+dp[1]+dp[0];
    dp[6] = dp[5]+dp[4]+dp[3]+dp[2]+dp[1]+dp[0];
    for(int i=7; i<=n; i ++){
        dp[i] = (dp[i-1]+dp[i])%MODULO;
        dp[i] = (dp[i-2]+dp[i])%MODULO;
        dp[i] = (dp[i-3]+dp[i])%MODULO;
        dp[i] = (dp[i-4]+dp[i])%MODULO;
        dp[i] = (dp[i-5]+dp[i])%MODULO;
        dp[i] = (dp[i-6]+dp[i])%MODULO;
    }
    ::cout << dp[n] << endl;
    return 0;
}