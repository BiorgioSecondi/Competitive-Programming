#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())
#define pq priority_queue

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using piii=pair<int,pii>;

#define MAXM int(2e9)
#define MAXN int(1e5)

#ifndef EVAL //ONLINE_JUDGE
    ifstream cin("i.txt");
    ofstream cout("o.txt");
#endif

int main(){
    ll N;
    ::cin >> N;
    int ans;
    pq<piii> dishes;
    vector<vector<int>> dp(MAXM);
    vector<int> bob(MAXN);
    fill(all(bob),0);
    fill(all(dp),bob);


    for(int i = 0 ; i<N;i++){
        int A,B,C;
        ::cin >> A >> B >> C;
        dishes.push({A+C,{A,B}});
    }




    ::cout << ans;

    return 0; 
}
