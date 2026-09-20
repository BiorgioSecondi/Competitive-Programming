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

void update(int k, int x){
    k+=segtree.size()/2;
    segtree[k]+=x;
    for(k/=2;k>0;k/=2){
        segtree[k]=segtree[2*k]+segtree[2*k+1];
    }
    return;
}

int query(int a, int b){
    if(a==b) return segtree[a];
    if(a%2==1) return query(a+1,b)+segtree[a];
    if(b%2==0) return query(a,b-1)+segtree[b];
    return query(a/2,b/2);
}

int main(){
    int N,Q;
    ::cin >> N >> Q;
    vector<int> sal(N);
    vector<int> comp;
    vector<pair<bool,pii>> quer(Q);
    
    for(int i = 0 ; i < N ; i++){
        ::cin >> sal[i];
        comp.pub(sal[i]);
    }
    for(int i = 0 ; i < Q ; i++){
        char temp;
        ::cin >> temp;
        quer[i].first=(temp=='?');
        if(quer[i].first){
            ::cin >> quer[i].second.first >> quer[i].second.second;
            comp.pub(quer[i].second.first);
            comp.pub(quer[i].second.second);
        }
        else{
            ::cin >> quer[i].second.first >> quer[i].second.second;
            quer[i].second.first--;
            comp.pub(quer[i].second.second);
        }
    }

    
    sort(all(comp));
    comp.resize(unique(all(comp))-comp.begin());
    segtree.resize(1 << (33-__builtin_clz(comp.size())));
    fill(all(segtree),0);
    auto it = comp.begin();

    for(int i = 0 ; i < N ; i++){
        update(lower_bound(all(comp),sal[i])-it,1);
    }



    for(int i = 0 ; i<Q;i++){
        if(quer[i].first){
            int l = (lower_bound(all(comp),quer[i].second.first)-it)+segtree.size()/2;
            int r = (lower_bound(all(comp),quer[i].second.second)-it)+segtree.size()/2;
            ::cout << query(l,r) << endl;
        }
        else{
            update(lower_bound(all(comp),sal[quer[i].second.first])-it,-1);
            sal[quer[i].second.first]=quer[i].second.second;
            update(lower_bound(all(comp),quer[i].second.second)-it,1);
        }
    }
    return 0; 
}
