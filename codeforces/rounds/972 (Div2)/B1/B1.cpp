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

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

void solve(){
    int N,M,Q;
    ::cin >> N >> M >> Q;
    vector<int> teac(M);
    for(int i = 0 ; i < M ; i++){
        ::cin >> teac[i];
    }
    teac.pub(N+1);
    teac.pub(0);
    sort(all(teac));
    while(Q--){
        int query;
        ::cin >> query;
        query;
        int a=0,b=M+1;
        while(a+1<b){
            int k = (a+b)/2;
            if(teac[k]>query){
                b=k;
            }
            else a=k;
        }
        if(a==0){
            ::cout << teac[b]-1 << '\n';
        }
        else if(b==M+1){
            ::cout << N-teac[a] << '\n';
        }
        else{
            ::cout << (teac[b]-teac[a])/2 << '\n';
        }
    }
}

int main(){
    ll t;

    ::cin >> t;
    while(t--){
        solve();
    }
    
    return 0; 
}
