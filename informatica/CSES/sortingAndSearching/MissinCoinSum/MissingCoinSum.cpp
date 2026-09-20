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
    vector<ll> C(n);
    for(auto &x:C) ::cin >> x;
    sort(all(C));
    ll sum = 0;
    ll ans = INT64_MAX;
    for(int i = 0 ; i < n ; i++){
        if(C[i] > sum + 1){
            ans = sum + 1;
            break;
        }
        sum += C[i];
    }
    ans = min(ans, sum+1 );
    ::cout << ans << endl;
    return 0;
}