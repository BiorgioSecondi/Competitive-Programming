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
    ll n,ans=0;
    ::cin >> n;
    vector<vector<int>> plane(n+3);
    vector<int> bob = {0,0};
    fill(all(plane),bob);
    for(int i = 1 ; i <= n ; i++){
        int x,y;
        ::cin >> x >> y;
        plane[x][y]=1;
        if(x>0){
            if(plane[x-1][1-y]==1 and plane[x+1][1-y]==1) ans++;
        }
        if(x>1){
            if(plane[x-2][y]==1 and plane[x-1][1-y]==1) ans++;
        }
        if(plane[x+2][y]==1 and plane[x+1][1-y]==1) ans++;
    }
    for(int i=0 ; i<=n;i++){
        if(plane[i][0]==1 and plane[i][1]==1) ans+=n-2;
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
