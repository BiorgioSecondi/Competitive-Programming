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

#ifndef EVAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    int N,D;
    ::cin >> N >> D;
    set<pii> P;
    int p;
    for(int i = 0 ; i < N ; i++){
        ::cin >> p;
        P.insert({p,i});
    }

    ll ans=0;

    for(auto x : P){
        auto r = P.lower_bound({x.first+D,0});
        if(r == P.end()) ans += N-x.second-1;
        else ans += (*r).second-x.second-1;
    }

    ::cout << ans << endl;
}