#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

const int MAXN=2e5;
const int K = 33-__builtin_clz(MAXN);
int st[K+1][MAXN];

int main(){
    int n,Q;
    ::cin >> n >> Q;
    for(int i = 0 ; i < n ; i++){
        int temp;
        ::cin >> temp;
        st[0][i]=temp;
    }
    for(int i = 1 ; i <= K ; i++){
        for(int j = 0 ; j + (1 << i) <= n;j++){
            st[i][j]=st[i-1][j]^st[i - 1][j + (1 << (i - 1))];
        }
    }
    for(int q = 0 ; q < Q ; q++){
        int l,r;
        ::cin >> l >> r;
        l--;
        r--;
        int ans = 0;
        for(int i = K; i >=0 ; i--){
            if((1<<i) <= (r - l + 1)){
                ans = ans^st[i][l];
                l+=1<<i;
            }
        }
        ::cout << ans << '\n';
    }
    return 0;
}