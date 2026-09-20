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

vector<vector<ll>> dp;

ll solve(const vector<ll> &data , int i, int j){

    bool turno = (j-i)%2 == (data.size()-1)%2;

    if(dp[i][j] != -INT64_MAX){
        return dp[i][j];
    }
    else  if(turno){
        return dp[i][j] = max(data[i] + solve(data,i+1,j) , data[j] + solve(data,i,j-1));
    }
    else{
        return dp[i][j] = min( solve(data,i+1,j) , solve(data,i,j-1) );
    }
}

int main(){
    ::ios::sync_with_stdio(false);
    ::cin.tie(nullptr);

    ll n;
    ::cin >> n;
    vector<ll> data(n);
    for(auto &x : data) ::cin >> x;

    dp.resize(n,vector<ll>(n,-INT64_MAX));

    int last_turn = ((n-1)%2 == 0);

    for(int i = 0 ; i < n ; i++){
        dp[i][i] = data[i]*last_turn;
    }

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         if(i<= j){
    //             ::cout << dp[i][j] << " ";
    //         }
    //         else{
    //             ::cout << "a ";
    //         }
    //     }
    //     ::cout << endl;
    // }

    ll ans = solve(data, 0, n-1);

    // ::cout << endl;

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         if(i<= j){
    //             ::cout << dp[i][j] << " ";
    //         }
    //         else{
    //             ::cout << "a ";
    //         }
    //     }
    //     ::cout << endl;
    // }

    ::cout << ans << endl;


    return 0;
}