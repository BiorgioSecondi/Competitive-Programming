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

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");   
#endif

int main(){
    int N;
    string C;
    ::cin >> C;
    N = C.length();
    int i =0;
    int ans = -INT_MAX;
    int consec;
    while(i<N){
        consec = 1;
        while (C[i]==C[i+1]){
            consec++;
            i++;
        }
        ans = max(ans,consec);
        i++;
    }
    ::cout << ans;
    return 0;
}