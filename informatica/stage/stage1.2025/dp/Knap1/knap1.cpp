#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pqi=priority_queue<int>;
using pqll=priority_queue<ll>;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

//#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    int N,W;
    ::cin >> N >> W;
    vector<int> w(N);
    vector<int> v(N);

    for(int i = 0 ; i < N ; i++){
        ::cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(N+1);
    vector<int> bob(W+1);
    fill(all(bob),0);
    fill(all(dp),bob);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j <= W ; j++){
            if(j+w[i]<=W){
                dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
            }
            if(i<N) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
    }

    ::cout << dp[N][W];
    return 0; 
}
