#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
    ifstream cin("i.txt");
    ofstream cout("o.txt");
#endif

class segtree{
    public:
        vector<ll> data;
        segtree(ll N){
            data.resize(1<<(65-__builtin_clz(N)));
            fill(all(data),0);
            data[0]=data.size();
        }
        void update(ll v,ll x){
            x+=data[0]/2;
            data[x]=v;
            for(x/=2;x>0;x/=2){
                data[x]=data[2*x]+data[2*x+1];
            }
            return;
        }
        ll query(int l, int r){
            if(l==r) return data[l];
            if(l%2==1) return query(l+1,r)+data[l];
            if(r%2==0) return query(l,r-1)+data[r];
            return query(l/2,r/2);
        }
        int size(){
            return data[0];
        }
};

int main(){
    ll N,Q;
    ::cin >> N >> Q;
    segtree tree(N);
    ll temp;
    for(int i = 0 ; i<N ; i++){
        ::cin >> temp;
        tree.update(temp,i);
    }
    while(Q--){
        int dec;
        ::cin >> dec;
        if(dec==1){
            ll k,u;
            ::cin >> k >> u;
            k--;
            tree.update(u,k);
        }
        else{
            ll l,r;
            ::cin >> l >> r;
            l--;
            r--;
            ::cout << tree.query(l+tree.size()/2,r+tree.size()/2) << '\n';
        }
    }
    return 0;
}