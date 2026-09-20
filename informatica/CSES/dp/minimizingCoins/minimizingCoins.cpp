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

int main(){
    ll n,x;
    ::cin >> n >> x;
    vector<int> coins(n);
    for(auto &c:coins) ::cin >> c;

    vector<ll> dp(x+1,INT64_MAX);
    dp[0] = 0;
    for(int i=0; i <= x ; i++){
        if(dp[i]== INT64_MAX){
            continue;
        }
        for(auto c:coins){
            if(i+c<=x){
                dp[i+c] = min(dp[i+c],1+dp[i]);
            }
        }
    }
    if(dp[x]==INT64_MAX){
        ::cout << -1 << endl;
    }
    else{
        ::cout << dp[x] << endl;
    }

    return 0;
}