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
    int N=0;
    ::cin >> N;
    vector<int> W(N);
    vector<int> H(N);
    for(int i = 0 ; i < N ; i++){
        ::cin >> W[i];
        ::cin >> H[i];
    }
    int Wmax=0,Hmax=0;
    for(int i = 0 ; i < N ; i++){
        Wmax = max(Wmax,W[i]);
        Hmax = max(Hmax,H[i]);
    }
    ::cout << 2*(Hmax+Wmax) << endl;
}

int main(){
    ll t;
    ::cin >> t;
    while(t--){
        solve();
    }
    
    return 0; 
}
