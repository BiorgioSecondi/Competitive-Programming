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
    string A="";
    string E="";
    string I="";
    string O="";
    string U="";
    
    for(int i = 0 ; i < N/5 ; i++){
        A+="a";
    }
    if(N%5>0){
        A+="a";
    }
    for(int i = 0 ; i < N/5 ; i++){
        E+="e";
    }
    if(N%5>1){
        E+="e";
    }
    for(int i = 0 ; i < N/5 ; i++){
        I+="i";
    }
    if(N%5>2){
        I+="i";
    }
    for(int i = 0 ; i < N/5 ; i++){
        O+="o";
    }
    if(N%5>3){
        O+="o";
    }
    for(int i = 0 ; i < N/5 ; i++){
        U+="u";
    }
    ::cout << A+E+I+O+U << '\n';
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
