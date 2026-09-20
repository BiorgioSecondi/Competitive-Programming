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
    int a,b;
    ::cin >> a >> b;

    vector<vector<ll>> dp(a+1,vector<ll>(b+1,0));

    for(int i = 1 ; i <= a ; i++){
        dp[i][1] = i-1;
    }
    for(int j = 1 ; j <= b ; j++){
        dp[1][j] = j-1;
    }

    for(int i = 2 ; i <= a ; i++){
        for(int j = 2 ; j <= b ; j++){
            if(i != j){
                dp[i][j] = INT64_MAX;
                // ::cout << "iterazione su (i,j) = " << "(" << i << "," << j << ")" << endl;
                for(int k = 1 ; k <= i/2 ; k++){
                    // ::cout << "     k = " << k << endl;
                    dp[i][j] = min(dp[i][j] , 1 + dp[k][j] + dp[i-k][j]);
                }
                for(int k = 1 ; k <= j/2 ; k++){
                    dp[i][j] = min(dp[i][j] , 1 + dp[i][k] + dp[i][j-k]);
                }
            }
        }
    }

    // for(int i = 0 ; i <= a ; i++){
    //     for(int j = 0 ; j <= b ; j++){
    //         ::cout << dp[i][j] << " ";
    //     }
    //     ::cout << endl;
    // }
    ::cout << dp[a][b] << endl;
}