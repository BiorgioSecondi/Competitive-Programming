#include <bits/stdc++.h>

using namespace std;
#define ll long long

#ifndef ONLINE_JUDGE
    ifstream cin("i.txt");
    ofstream cout("o.txt");
#endif

const int MAXN = 2e5;
const int K = 33-__builtin_clz(MAXN);
int st[K+1][MAXN];

int main(){
    ll N,Q;
    ::cin >> N >> Q;
    for(int i = 0 ; i < N ; i++){
        ::cin >> st[0][i];
    }
    for(int i=1;i<=K;i++){
        for(int j=0;(j+(1<<i))<=N;j++){
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    while(Q--){
        ll l,r;
        ::cin >> l >> r;
        l--,r--;
        int ans = INT_MAX;
        for(int i = K;i>=0;i--){
            if((1<<i)<=r-l+1){
                ans = min(ans,st[i][l]);
                l+=(1<<i);
            }
        }
        ::cout << ans << '\n';
    }
}