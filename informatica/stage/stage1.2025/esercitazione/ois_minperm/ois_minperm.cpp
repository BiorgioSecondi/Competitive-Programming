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

vector<int> DSU;
vector<int> dim;

int find(int a){
    if(a==DSU[a]) return a;
    DSU[a]=find(DSU[a]);
    return DSU[a];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(dim[a]>dim[b]) swap(a,b);
    DSU[a]=b;
    dim[b] += dim[a];
    dim[a]=0;
}

int main(){
    int N,K;
    ::cin >> N >> K;
    vector<int> P(N);
    vector<int> L(K);
    DSU.resize(N);
    dim.resize(N);
    fill(all(dim),1);

    for(int i = 0 ; i < N ; i++){
        ::cin >> P[i];
        DSU[i]=i;
    } 
    for(int i = 0 ; i < K ; i++) ::cin >> L[i];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j<K;j++){
            if(i+L[j]<N) merge(i,i+L[j]);
        }
    }
    vector<pqi> valori(N);

    for(int i = 0 ; i < N ; i++){
        valori[find(i)].push(-P[i]);
    }
    for(int i = 0 ; i < N ; i++){
        int value =-valori[find(i)].top();
        valori[find(i)].pop();
        ::cout << value << " "; 
    }
    return 0; 
}
