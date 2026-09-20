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
    int N;
    ll ans;
    ::cin >> N;
    multiset<int> MAD;
    deque<int> arr(N);
    for(int i = 0; i<N;i++){
        int temp;
        ::cin >> temp;
        MAD.insert(temp);
        arr[i] = temp;
    }
    while(MAD.count(0)!=N){
        for(auto x : arr) ans+=x;
        for(int i = 0 ; i<N ; i++){
            deque<int> arr(N-1); 
        }
    }
    ::cout << ans << '\n';
}

int main(){
    int T;
    ::cin >> T;
    for(int i = 0 ; i < T ; i++){
        solve();
    }

    return 0; 
}