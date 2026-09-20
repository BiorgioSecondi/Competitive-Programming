#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())
#define pq priority_queue

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

void solve(){
    ll N,M;
    ::cin >> N >> M;
    ll ans=0;
    vector<string> chat(N);
    string narek="narek";


    for(ll i = 0 ; i < N ; i++){
        ::cin >> chat[i];
    }
    for(ll i = 0 ; i < N ; i++){
        ll it=0;
        ll valore=0;
        for(auto x:chat[i]){
            if(x==narek[it]){
                if(it==4) valore+=(ll)(5);
                it++;
                it%=5;
            }
            else if(x=='n' or x=='a' or x=='r' or x=='e' or x=='k'){
                valore--;
            }
        }
        if(valore>0) ans+=valore;
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
