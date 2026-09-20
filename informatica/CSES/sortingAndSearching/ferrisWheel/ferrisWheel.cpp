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
    ll n,x;
    ::cin >> n >> x;
    multiset<int> pesi;
    
    ll ans=0;
    for(int i=0; i < n ; i++){
        int temp;
        ::cin >> temp;
        pesi.insert(temp);
    }

    while(!pesi.empty()){
        auto it_grasso  = --pesi.end();
        int val_grasso = *(it_grasso);
        auto it_leggero = pesi.upper_bound(x-val_grasso);
        if(it_leggero == pesi.begin()){
            pesi.erase(it_grasso);
            ans++;
        }
        else{
            pesi.erase(it_grasso);
            if(!pesi.empty()) pesi.erase(--it_leggero);
            ans++;
        }
    }
    ::cout << ans << endl;


    return 0;
}