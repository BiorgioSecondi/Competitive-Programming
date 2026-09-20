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
 
vector<int> segtree;
 
template<typename T>
void stampa( vector<T> &arr, string tag){
    #ifdef ONLINE_JUDGE
        return; 
    #endif
    ::cout << tag << '\n';
    for(T &x:arr) ::cout << x << '\n';
    ::cout << "-------------------------" << '\n';
}
 
void update(int x, int v){
    x+=segtree.size()/2;
    segtree[x]=v;
    for (x/=2 ; x > 0; x/=2){
        segtree[x]=segtree[2*x]+segtree[2*x+1];
    }
    return;
}
 
int search(int k, int pos){
    if(pos>=segtree.size()/2) return pos-(segtree.size()/2);
    if(segtree[2*pos]>=k) return search(k, 2*pos);
    return search(k-segtree[2*pos],2*pos+1);
}
 
int main(){
    int N;
    ::cin >> N;
    segtree.resize(1<<(33-__builtin_clz(N)));
    fill(all(segtree),0);
    vector<int> list(N);
 
    for(int i=0;i<N;i++){
        ::cin >> list[i];
        update(i,1);
    } 
 
    while(N--){
        int q;
        ::cin >> q;
        int ans = search(q,1);
        ::cout << list[ans] << '\n';
        update(ans,0);
    }
 
    return 0;
}