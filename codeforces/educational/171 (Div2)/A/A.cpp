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
    int X,Y,K;
    ::cin >> X >> Y >> K;
    pii A,B,C,D;
    A={0,0};
    B={int(1+(K/sqrt(2))),int(1+(K/sqrt(2)))};
    C={int(1+(K/sqrt(2))),0};
    D={0,int(1+(K/sqrt(2)))};
    ::cout << A.first << " " << A.second << " " << B.first << " " << B.second << endl;
    ::cout << C.first << " " << C.second << " " << D.first << " " << D.second << endl;
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
