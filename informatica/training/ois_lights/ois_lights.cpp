#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())
#define pq priority_queue<int>

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#ifndef EVAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

using namespace std;

int main() {

    int N, C;
    ::cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        ::cin >> L[i];
    }
    unordered_multiset<int> S;
    unordered_set<int> F;
    int l=0,r=0;
    int ans=INT_MAX;

    while(r<N){
        S.insert(L[r]);
        F.insert(L[r]);
        while(S.count(L[l])>1){
            S.erase(S.find(L[l]));
            l++;
        }
        if(F.size()==C){
            ans = min(ans, r-l+1);
        }
        r++;
    }

    ::cout << ans << endl;  // print the result
    return 0;
}
