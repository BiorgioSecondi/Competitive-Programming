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
    int K;
    ::cin >> N >> K;
    if(N==1 and K==1){
        ::cout << "caso banale" << endl;
        ::cout << '-' << endl;
        return;
    }
    char M;
    int top=0;
    int bottom=0;
    int bho=0;
    for(int i = 0; i< K; i++){
        ::cin >> M;
        bho += M=='2';
        top += M=='0';
        bottom += M=='1';
    }
    vector<char> ans(N);
    fill(all(ans),'+');
    int i=0,j=0;
    while(i < top){
        ans[i]='-';
        i++;
    }
    while(j < bottom){
        ans[N-1-j]='-';
        j++;
    }
    ::cout << " " << top << " " << bottom << " " << bho << endl;
    for(auto x: ans) ::cout << x;
    ::cout << endl;
    while(bho>0){
        ans[i]='?';
        ans[N-1-j]='?';
        bho--;
        i++;
        j++;
    }

    for(auto x: ans) ::cout << x;
    ::cout << endl;
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
