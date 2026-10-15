#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <vector>
#include <ranges>
using namespace std;

using ll = long long;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
ifstream cin("input.txt");
ofstream cout("output.txt");
#endif

int main() {
    ios::sync_with_stdio(false);
    ::cin.tie(nullptr);

    ll n;
    ::cin >> n;

    vector<pair<ll,ll>> H(n);
    for(int i = 0 ; i < n ; i++){
        ll temp;
        ::cin >> temp;
        H[i] = {temp,i};
    }

    sort(H.rbegin(),H.rend());

    set<ll> dp;
    dp.insert(H[0].second);

    ll sol=0;

    for(int i = 1; i< n ; i++){
        auto curr = dp.insert(H[i].second).first;
        ll d = INT64_MAX;
        if(curr != dp.begin()){
            d = min(d,abs(*curr-*(--curr)));
            curr++;
        }
        if(curr != --dp.end()){
            d = min(d,abs(*curr-*(++curr)));
        }
        if(d != INT64_MAX){
            sol += d;
        }
    }

    ::cout << sol << endl;
}