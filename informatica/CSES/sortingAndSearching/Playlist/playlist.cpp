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
    vector<int> S(n);
    for(auto &x:S) ::cin >> x;

    map<int,int> ref;
    for(auto x: S){
        ref[x] = -1;
    }

    int i = 0;
    int j = 0;
    int ans = 0;

    ref[S[i]] = i; 

    // for(auto x: ref) ::cout << "(" << x.first << "," << x.second << ")" << " ";
    // ::cout << endl << endl;

    while(j < n){

        ans = max( ans , j - i + 1);

        // ::cout << "inizio iterazione con i = " << i << " e j = " << j << endl;
        // for(auto x: ref) ::cout << "(" << x.first << "," << x.second << ")" << " ";
        // ::cout << endl << endl;

        j++;

        if( ref[S[j]] != -1 ){
            while( i <= ref[S[j]] ){
                ref[S[i]] = -1;
                i++;
            }
        }

        ref[S[j]] = j;

    }

    ::cout << ans << endl;
    

    return 0;
}