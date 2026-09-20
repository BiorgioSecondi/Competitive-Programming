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
    int N; 
    ::cin >> N;
    vector<int> stalin(N);

    for(int i = 0 ; i < N ; i++){
        ::cin >> stalin[i];
    }

    for(int i = 0 ; i < stalin.size()-1 ;i++){
        while(stalin[i]>stalin[i+1] and i < stalin.size()-1) stalin.erase(stalin.begin()+i+1);
    }

    int ans=1;
    for(int i = 0 ; i < stalin.size() - 1 ; i++){
        int partial=1;
        while(stalin[i]==stalin[i+1] and i < stalin.size()-1){
            i++;
            partial++;
        }
        ans = max(partial,ans);
    }

    ::cout << stalin.size()-ans << endl;
}

int main(){
    ll t;

    ::ios::sync_with_stdio(false);
    ::cin.tie(nullptr);

    ::cin >> t;
    while(t--){
        solve();
    }
    
    return 0; 
}