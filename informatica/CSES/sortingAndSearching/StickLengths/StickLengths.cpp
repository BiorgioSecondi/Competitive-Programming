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
    ll n;
    ::cin >> n;
    vector<int> S(n);
    for(auto &x: S) ::cin >> x;
    sort(all(S));
    ll ans = 0;
    ll L = (S[(n-1)/2]+S[n/2])/2;
    for(auto x:S){
        ans += abs(x-L);
    }
    ::cout << ans << endl;
}