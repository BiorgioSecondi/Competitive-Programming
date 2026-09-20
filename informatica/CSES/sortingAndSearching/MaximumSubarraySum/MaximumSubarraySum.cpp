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
    vector<ll> A(n);
    for(auto &x:A) ::cin >> x;

    vector<ll> prefix(n+1);
    prefix[0]=0;
    for(ll i = 0 ; i < n ; i++){
        prefix[i+1] = prefix[i] + A[i];
    }

    ll i=0,j=1;
    ll min = prefix[i];
    ll ans = -INT64_MAX;
    while(j< n+1){
        ans = max(ans,prefix[j]-min);
        if(prefix[j] < min){
            i = j;
            min = prefix[i];
        }
        j++;
    }
    ::cout << ans << endl;
    return 0;
}