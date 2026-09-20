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

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");   
#endif

void solve(){
    ll x,y;
    ll m,M;
    ::cin >> x >> y;
    M=max(x,y);
    m=min(x,y);
    ll base = (M*M)-M+1;
    ll ans;
    if(M%2==0){
        if(x>y){
            ans = base + M - m;
        }
        else{
            ans = base - M + m;
        }
    }
    else{
        if(x>y){
            ans = base - M + m;       
        }
        else{
            ans = base + M - m;
        }
    }
    ::cout << ans << endl;
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
