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
    vector<pii> differenze;
    for(int i=0; i < n ; i++){
        int a,b;
        ::cin >> a >> b;
        differenze.pub({a,1});
        differenze.pub({b,-1});
    }
    sort(differenze.begin(),differenze.end());
    ll ans=0;
    ll sum=0;
    for(int i=0; i<2*n; i++){
        sum += differenze[i].second;
        ans = max(ans,sum);
    }
    ::cout << ans << endl;
    return 0;
}