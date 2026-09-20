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
 
struct node{
    ll prefix;
    ll sum;
};
 
node build(int x){
    node ans;
    ans.sum = x;
    ans.prefix = x>0 ? x : 0;
    return ans;
}
 
node combine(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    ans.prefix = max(a.prefix,max(a.sum+b.prefix,ans.sum));
    return ans;
}
 
vector<node> segtree;
 
void update(int val, int pos){
    pos+=segtree.size()/2;
    segtree[pos]=build(val);
    for(pos/=2;pos>0;pos/=2){
        segtree[pos]=combine(segtree[2*pos],segtree[2*pos+1]);
    }
    return;
}
 
node query(int l, int r){
    if(l==r) return segtree[l];
    if(l%2==1) return combine(segtree[l],query(l+1,r));
    if(r%2==0) return combine(query(l,r-1),segtree[r]);
    return query(l/2,r/2);
}
 
int main(){
    int N,Q;
    ::cin >> N >> Q;
    segtree.resize(1<<(33-__builtin_clz(N)));
 
    node bob = build(0);
    fill(all(segtree),bob);
 
    for(int i = 0 ; i < N ; i++){
        int temp;
        ::cin >> temp;
        update(i,temp);
    }
 
    while(Q--){
        int dec;
        ::cin >> dec;
        if(dec == 1){
            ll k,u;
            ::cin >> k >> u;
            k--;
            update(u,k);
        }
        else{
            int l,r;
            ::cin >> l >> r;
            l--,r--;

            ::cout << query(l+segtree.size()/2,r+segtree.size()/2).prefix << endl;
        }
    }
 
    return 0;
}