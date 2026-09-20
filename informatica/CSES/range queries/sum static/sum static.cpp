#include <bits/stdc++.h>

using namespace std;
#define ll long long

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    ll N,Q;
    ::cin >> N >> Q;
    vector<ll> prefix(N+1);
    fill(prefix.begin(),prefix.end(),0);

    for(int i = 1 ; i < N+1 ; i++){
        ::cin >> prefix[i];
    }
    for(int i = 1; i<N+1;i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i = 0;i<Q;i++){
        ll l,r;
        ::cin >> l >> r;
        ::cout << prefix[r]-prefix[l-1] << '\n';
    }
    return 0;
}