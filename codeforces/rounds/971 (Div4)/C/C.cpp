#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())
#define pq priority_queue<int>

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

void solve(){
    ll x,y,k;
    ll ans=0;
    ::cin >> x >> y >> k;
    ll p = min(x,y);
    ans+=(p/k)*2;
    x-=(ans*k)/2;
    y-=(ans*k)/2;

    while(x!=0 or y!=0){
        if(x<=k) x=0;
        else x-=k;
        ans++;
        if(x==0 and y==0) break;
        if(y<=k) y=0;
        else y-=k;
        ans++;
    }

    ::cout << ans << '\n';
}

int main(){
    ll t;

    ::ios::sync_with_stdio(false);
    ::cin.tie(nullptr);

    ::cin >> t;
    while(t--){
        solve();
    }
    
    return 0; 
}
