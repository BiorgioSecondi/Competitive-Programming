#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pqi=priority_queue<int>;
using pqll=priority_queue<ll>;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    int N;
    ::cin >> N;
    vector<int> H(N);
    for(int i = 0 ; i < N ; i++){
        ::cin >> H[i];
    }

    vector<int> p(N);
    p[0]=0;
    p[1]=abs(H[1]-H[0]);
    for(int i = 2 ; i < N; i++){
        p[i]=min(p[i-1]+abs(H[i]-H[i-1]),p[i-2]+abs(H[i]-H[i-2]));
    }
    ::cout << p[N-1];   
    return 0; 
}
