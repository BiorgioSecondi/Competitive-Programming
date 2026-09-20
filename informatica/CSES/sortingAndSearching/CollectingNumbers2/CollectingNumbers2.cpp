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
    #define debug(x) ::cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    ll n,m;
    ::cin >> n >> m;

    vector<int> A(n);
    for(auto &x:A) ::cin >> x;
    vector<pii> S(n);

    for(int i = 0 ; i < n ; i++){
        S[i].first = A[i];
        S[i].second = i;
    }

    sort(all(S));

    int ans = 1;
    for(int i = 0; i < n-1 ; i++){
        ans += (S[i].second > S[i+1].second);
    }

    // for(int i = 0 ; i < n ; i++) ::cout << S[i].second << " ";
    // ::cout << endl;

    while(m--){
        int a,b;
        ::cin >> a >> b;
        a--;
        b--;

        int pos_a = A[a] - 1;
        int pos_b = A[b] - 1;

        // ::cout << "iterazione con scambio di  pos_a = " << pos_a << " e pos_b = " << pos_b << endl;

        set<pii> coda;
        if(pos_a > 0) coda.insert({pos_a - 1 , pos_a});
        if(pos_a < n-1) coda.insert({pos_a , pos_a + 1});
        if(pos_b > 0) coda.insert({pos_b - 1 , pos_b});
        if(pos_b < n-1) coda.insert({pos_b , pos_b + 1});

        for(auto p : coda){
            ans -= S[p.first].second > S[p.second].second; 
        }

        swap(S[pos_a],S[pos_b]);
        swap(A[a],A[b]);

        for(auto p : coda){
            ans += S[p.first].second > S[p.second].second; 
        }

        ::cout << ans << endl;
    }

    return 0;
}