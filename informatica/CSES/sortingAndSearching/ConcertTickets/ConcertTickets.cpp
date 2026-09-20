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
    ::cin >> n >> m ;
    multiset<int> prices;
    for(int i = 0 ; i < n ; i++){
        int temp;
        ::cin >> temp;
        prices.insert(temp);
    }
    for(int i= 0 ; i< m ; i++){
        int customer;
        ::cin >> customer;
        auto ticket_it = prices.upper_bound(customer);
        if(ticket_it == prices.begin()){
            ::cout << -1 << endl;
            continue;
        }
        else{
            int ticket_val = *(--ticket_it);
            prices.erase(ticket_it);
            ::cout << ticket_val << endl;
            continue;
        }
    }
    return 0;
}