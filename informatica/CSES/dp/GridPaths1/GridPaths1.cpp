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

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            char input;
            ::cin >> input;
            if(input == '.'){
                dp[i][j] = -1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    dp[0][1] = 1;
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(dp[i][j]== -1){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= MODULO;
            }
        }
    }

    ::cout << dp[n][n] << endl;

    return 0;
}