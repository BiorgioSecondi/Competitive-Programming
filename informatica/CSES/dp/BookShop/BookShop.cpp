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
    vector<int> C(n);
    vector<int> V(n);

    for(auto &c : C) ::cin >> c;
    for(auto &v : V) ::cin >> v;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= x ; j++){
            dp[i][j] = dp[i-1][j];
            if(j-C[i-1] >= 0){
                dp[i][j] = max(dp[i][j],(dp[i-1][j-C[i-1]])+V[i-1]);
            }
        }
    }
    /*
    for(auto vet:dp){
        for( auto m:vet){
            ::cout << m << "  ";
        }
        ::cout << endl;
    }
    */
    ::cout << dp[n][x];

    return 0;
}