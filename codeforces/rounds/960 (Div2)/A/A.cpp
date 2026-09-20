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
    ::cin >> N;
    multiset<int> arr;
    for(int i = 0 ; i < N ; i++){
        int temp;
        ::cin >> temp;
        arr.insert(temp);
    }
    bool ans=false;
    for(int i = 0 ; i < 50 ; i++){
        if(arr.count(i)%2!=0){
            ans = true;
            break;
        } 
    }
    if( ans ) ::cout << "YES" << '\n';
    else ::cout << "NO" << '\n';
}

int main(){
    int T;
    ::cin >> T;
    for(int i = 0 ; i < T ; i++){
        solve();
    }

    return 0; 
}
