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
    int N,K;
    ::cin >> N >> K;
    vector<int> H(N);
    for(int i = 0 ; i < N ; i++){
        ::cin >> H[i];
    }

    vector<int> p(N);
    fill(all(p),INT_MAX);
    p[0]=0;
    p[1]=abs(H[1]-H[0]);
    for(int i = 2 ; i < N; i++){
        for(int j = i-K>0 ? i-K : 0 ; j<i ; j++){
            p[i]=min(p[i],p[j]+abs(H[i]-H[j]));
        }
    }
    ::cout << p[N-1];   
    return 0; 
}
