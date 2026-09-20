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
    int N;
    ::cin >> N;
    vector<ll> A(N);
    for(int i = 0 ; i < N ; i++) ::cin >> A[i];
    if(N%2==1){
        ll ans=INT64_MAX;
        for(int x = 0 ; x < N ; x++){
            ll par=1;
            for(int i = 0; i < N-1;i+=2){
                i += i==x;
                par=max(par,A[i+1]-A[i]);
            }
            ans = min(par,ans);
        }
        ::cout << ans << endl;
    }
    else{
        ll ans=1;
        for(int i = 0; i < N-1;i+=2){
            ans=max(ans,A[i+1]-A[i]);
        }
        ::cout << ans << endl;
    }
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
