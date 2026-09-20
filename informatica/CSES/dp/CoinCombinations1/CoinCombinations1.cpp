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

    vector<ll> dp(x+1,0);
    dp[0] = 1;
    for(int i=0; i <= x ; i++){
        if(dp[i] == 0){
            continue;
        }
        for(auto c:coins){
            if(i+c<=x){
                dp[i+c] += dp[i];
                dp[i+c] %= MODULO;
            }
        }
    }
    ::cout << dp[x] << endl;

    return 0;
}