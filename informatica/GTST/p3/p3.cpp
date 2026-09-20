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
    int N,L;
    ::cin >> N >> L;

    vector<vector<int>> timeline(L);
    int p,d;
    for(int i = 0 ; i < N ; i++){
        ::cin >> p >> d;
        timeline[(L+d)%L].pub(p);
    }

    pq choose;
    ll ans=0;

    for(int i=L-1;i>-1;i--){
        for(auto x:timeline[i]) choose.push(x);
        if(!choose.empty()){
            ans += choose.top();
            choose.pop();
        }
    }

    ::cout<<ans;

    return 0;
}