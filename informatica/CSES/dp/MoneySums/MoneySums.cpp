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
    ios_base::sync_with_stdio(false);
    ::cin.tie(NULL);

    int n;
    ::cin >> n;

    vector<int> V(n);

    ll sum=0;
    ll ans=0;

    for(auto &v: V){
        ::cin >> v;
        sum += v;
    }
    
    vector<vector<bool>> dp(2,vector<bool>(sum + 1,false));
    dp[0][0] = true;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < sum ; j++){
            if(dp[i%2][j]){
                dp[(i+1)%2][j + V[i]] = true;
                dp[(i+1)%2][j] = true;
            }
        }
        // ::cout << "iterazione dell'elemento " << i << endl;
        // for(int i = 0 ; i < 2 ; i++){
        //     for(int j = 0 ; j < sum + 1; j++){
        //         ::cout << dp[i][j] << " ";
        //     }
        //     ::cout << endl;
        // }
    }

    for(int i = 1 ; i < sum + 1; i++){
        if(dp[(n)%2][i]){
            ans++;
        }
    }
    ::cout << ans << endl;
    for(int i = 1 ; i < sum + 1; i++){
        if(dp[(n)%2][i]) ::cout << i << " ";
    }
    ::cout << endl;

    return 0;
}