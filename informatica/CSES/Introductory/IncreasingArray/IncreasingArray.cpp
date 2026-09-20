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

//#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");   
#endif
int main(){
    ll N;
    ::cin >> N;
    vector<ll> A(N);
    for (auto &x : A) ::cin >> x;
    ll i = 0;
    ll somma;
    ll ans = 0;
    ll M =-INT64_MAX;
    ll len;
    while (i<N-1){
        len = 0;
        somma=0;
        M = max(A[i],M);
        while(A[i+1]<M and i<N-1){
            i++;
            len++;
            somma+=A[i];
        }
        ans += (M*len) - somma;
        i++;
    }
    ::cout << ans;
    return 0;
}