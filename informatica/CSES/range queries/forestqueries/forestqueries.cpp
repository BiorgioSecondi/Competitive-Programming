#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define all(x) x.begin(),x.end()
 
#ifndef ONLINE_JUDGE
    ifstream cin("i.txt");  
    ofstream cout("o.txt");
#endif
 
int main(){
    ll N,Q;
    ::cin >> N >> Q;
    vector<vector<int>> prefix(N+1);
    vector<int> bob(N+1);
    fill(all(bob),0);
    fill(all(prefix),bob);
 
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j<=N ; j++){
            char temp;
            ::cin >> temp;
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            if(temp=='*') prefix[i][j]++;
        }
    }
    while(Q--){
        int y1,x1,y2,x2;
        ::cin >> y1 >> x1 >> y2 >> x2;
        int ans = prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1];
        ::cout << ans << '\n';
    }
    return 0;
}