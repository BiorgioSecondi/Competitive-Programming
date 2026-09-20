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


//ifstream cin("input.txt");
//ofstream cout("output.txt");

void solve(){
    int n,x,y;
    ::cin >> n >> x >> y;
    x--;
    y--;
    vector<int> ans(n);
    fill(all(ans),1);

    for(int i = y-1;i>-1;i-=2){
        ans[i] = -1;
    }
    for(int i = x+1;i<n;i+=2){
        ans[i] = -1;
    }

    for(auto x : ans) ::cout << x << " ";
    ::cout << "\n";
}

int main(){
    int T;
    ::cin >> T;
    for(int i = 0 ; i < T ; i++){
        solve();
    }

    return 0; 
}