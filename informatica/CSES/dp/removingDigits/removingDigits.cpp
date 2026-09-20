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

vector<int> dp;

int recursive_dp(int N){
    //::cout << "esecuzione ricorsiva con " << N << endl;
    int ans = INT_MAX;
    //::cout << "dp[N] vale " << dp[N] << endl;
    if(dp[N] != INT_MAX){
        return dp[N];
    }
    int temp = N;
    while(temp > 0){
        //::cout << "ciclo while con temp = " << temp << endl;
        int digit = temp % 10;
        temp /= 10;
        if (digit == 0) continue;
        ans = min(ans, 1+recursive_dp(N - digit));
    }
    return dp[N] = ans;
}

int main(){
    ll n;
    ::cin >> n;

    dp.resize(n+1);

    fill(all(dp),INT_MAX);

    dp[0]=0;

    ::cout << recursive_dp(n) << endl;
    return 0;
}