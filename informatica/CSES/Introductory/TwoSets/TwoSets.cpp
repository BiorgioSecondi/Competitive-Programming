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
    ll n;
    ::cin >> n; 
    ll r = n%4;
    unordered_set<int> uno;
    unordered_set<int> due;
    if(r==0 or r==3){
        while(n>3){
            uno.insert(n-1);
            uno.insert(n-2);
            due.insert(n);
            due.insert(n-3);
            n-=4;
        }
        if(n==3){
            uno.insert(1);
            uno.insert(2);
            due.insert(3);
        }
        ::cout << "YES";
        ::cout << endl << uno.size() << endl;
        for(auto x:uno) ::cout << x << " ";
        ::cout << endl << due.size() << endl;
        for(auto x:due) ::cout << x << " ";
    }
    else{
        ::cout << "NO" << endl;
    }
    return 0;
}