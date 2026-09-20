#include <bits/stdc++.h>

using namespace std;

#define s(x) x+segtree.size()/2
#define flip(x) x = x*(-1)
#define ll long long

int N, Q;

struct node {
    ll psum;
    ll maxPref;
    ll minPref;
    ll evenSuff;
    ll oddSuff;
    ll res;
    ll len;
};

vector<node> segtree;

node gen(int k){
    node ans;
    ans.psum = k;
    ans.len = 1;
    ans.maxPref = k;
    ans.minPref = k;
    ans.evenSuff = 0;
    ans.oddSuff = k;
    ans.res = k;
    return ans;
}

node combine(node a, node b){
    node ans;
    ans.len = a.len + b.len;
    bool aeven = a.len%2==0;
    bool beven = b.len%2==0;

    //ok la somma totale è facile da calcolare

    ans.psum = aeven ? a.psum + b.psum : a.psum - b.psum;

    //ora calcoliamo i prefissi, non troppo difficile
    if(aeven){
        ans.maxPref = max(a.maxPref , a.psum + b.maxPref);
        ans.minPref = min(a.minPref , a.psum + b.minPref);
    }
    else{ //a è dispari
        ans.maxPref = max(a.maxPref , a.psum - b.minPref);
        ans.minPref = min(a.minPref , a.psum - b.maxPref);
    }

    //ora proviamo con i suffissi

    if(beven){
        ans.evenSuff = max(b.evenSuff,a.evenSuff+b.psum);
        ans.oddSuff = max(b.oddSuff, a.oddSuff-b.psum);
    }
    else{ // b è dispari
        ans.evenSuff = max(b.evenSuff , a.oddSuff - b.psum);
        ans.oddSuff = max(b.oddSuff , a.evenSuff + b.psum);
    }

    // ok, ora facciamo res e abbiamo finito, calcoliamo prima i parziali usando odd e even suff
    ll partial1 = a.oddSuff - b.minPref;
    ll partial2 = a.oddSuff - b.maxPref;
    ll partial3 = a.evenSuff + b.maxPref;
    ll partial4 = a.evenSuff + b.minPref;
 
    ans.res = max(max(a.res , b.res) , max(max(partial1,partial2),max(partial3,partial4)) );

    return ans;
}

void update(int v, int x){
    x = s(x);
    segtree[x] = gen(v);
    for (x /= 2; x >= 1; x /= 2){
        segtree[x] = combine(segtree[2*x],segtree[2*x+1]);
    }
}

node query(int l, int r){
    if(l==r) return segtree[l];
    if(l%2==1) return combine(segtree[l],query(l+1,r));
    if(r%2==0) return combine(query(l,r-1),segtree[r]);
    return query(l/2,r/2);
}

int main() {
    #ifndef EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> N >> Q;
    segtree.resize(1 << (33-__builtin_clz(N)));
    for(int i = 0; i < segtree.size();i++){
        segtree[i] = gen(0);
    }

    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        update(temp,i);
    }

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--;
            update(b,a);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(s(l),s(r)).res << endl;
        }
    }

    return 0;
}