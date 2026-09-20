#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
    ifstream cin("i.txt");
    ofstream cout("o.txt");
#endif

ll combine(ll a,ll b){
    return a+b;
}

class segtree{
    public:
        vector<ll> data;
        segtree(ll N, const vector<ll> &arr, ll neutro){
            data.resize(1<<(65-__builtin_clz(N)));
            fill(all(data),neutro);
            data[0]=data.size();
            for(ll i = 0;i<N;i++){
                data[i+data[0]/2]=arr[i];
            }
            for(ll j = data[0]/2; j/2>0;j/=2){
                for(ll i = j/2; i<j ; i++){
                    data[i]=combine(data[2*i],data[2*i+1]);
                }
            }
        }
        void update(ll v,ll x){
            x+=data[0]/2;
            data[x]+=v;
            for(x/=2;x>0;x/=2){
                data[x]=combine(data[2*x],data[2*x+1]);
            }
            return;
        }
        ll query(int l, int r){
            if(l==r) return data[l];
            if(l%2==1) return combine(data[l],query(l+1,r));
            if(r%2==0) return combine(query(l,r-1),data[r]);
            return query(l/2,r/2);
        }
        ll size(){
            return data[0];
        }
};

int main(){
    int N,Q;
    ::cin >> N >> Q;
    vector<ll> arr(N);
    for(ll i=0;i<N;i++){
        ::cin >> arr[i];
    }
    for(ll i=N-1;i>0;i--){
        arr[i]-=arr[i-1];
    }

    segtree tree(N,arr,0);

    while(Q--){
        int dec;
        ::cin >> dec;
        if(dec==1){
            ll a,b,u;
            ::cin >> a >> b >> u;
            a--;
            b--;
            tree.update(u,a);
            tree.update(-u,b+1);
        }
        else{
            ll k;
            ::cin >> k;
            ::cout << tree.query((tree.size()/2),k-1+(tree.size()/2)) << '\n';
        }
    }

    return 0;
}