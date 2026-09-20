#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pqi = priority_queue<int>;
using pqll = priority_queue<ll>;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
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

int main(){
    ll N;
    ::cin >> N;
    vector<int> V(N);

    for(auto &x:V) ::cin >> x;
    sort(all(V));
    ll i=1;
    ll ans = 0;
    while(i<N){
        ans++;
        i++;
        while(i<N and V[i]==V[i-1]){
            i++;
        }
        
    }
    if(V[0]!=V[1]) ans++;
    ::cout << ans << endl;

    return 0;
}