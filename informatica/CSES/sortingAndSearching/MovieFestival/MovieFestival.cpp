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
    ll n;
    ::cin >> n;
    vector<pii> tasks(n);
    for(int i = 0 ; i < n ; i++){  
        ::cin >> tasks[i].second >> tasks[i].first;  //i tempi di fine sono .first mentre i tempi d'inizio sono .second
    }
    sort(all(tasks));

    ll ans=1;
    ll i=1;
    ll curr=0;

    while (i<n){
        while(tasks[i].second < tasks[curr].first and i<n){   //clean up
            i++;
        } 
        if(i>= n) break;
        ans++;                                      //Greedy choice 
        curr=i;
        i++;                                          //Tail Recursion
    }
    ::cout << ans << endl;

    return 0;
}