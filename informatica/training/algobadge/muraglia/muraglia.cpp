#include <utility>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define s(x) x+(segtree.size()/2)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

vector<int> segtree;
int L;

void cambia(int x, int v){
    x = s(x);
    segtree[x] = v;
    for(x /= 2 ; x >= 1 ; x /= 2){
        segtree[x] = max(segtree[2*x],segtree[2*x+1]);
    }
}

int query(int dove, int v, int tl, int tr, int l, int r, int x){

    if(tl>r || tr<l) return -1;
    if(segtree[v] <= x) return -1;

    if(tl == tr) return tl;

    int tm = tl + (tr-tl)/2;

    if(dove > 0){
        int right = query(dove,2*v+1,tm+1,tr,l,r,x);
        if(right != -1) return right;
        else return query(dove,2*v,tl,tm,l,r,x);
    }
    else{
        int left = query(dove,2*v,tl,tm,l,r,x);
        if(left != -1) return left;
        else return query(dove,2*v+1,tm+1,tr,l,r,x);
    }
}

void inizializza(int N, vector<int> H) {

    L = N;
    segtree.resize(1 << (33-__builtin_clz(N)));
    for(int i = 0 ; i < segtree.size() ; i++ ) segtree[i] = 0;
    
    for(int i=0;i<N;i++) {
        cambia(i,H[i]);
    }
    
	return;
}

pair<int, int> chiedi(int x) {
    pair<int,int> ans;

    ans.first = query(1,1,0,(segtree.size()/2)-1,0,x,segtree[s(x)]);
    if(ans.first == -1) ans.first = 0;


    ans.second = query(-1,1,0,(segtree.size()/2)-1,x,segtree.size()/2-1,segtree[s(x)]);
    if(ans.second == -1) ans.second = L-1;

    return ans;
}

#ifndef EVAL

int main() {
	// Reading input

    ifstream cin("input.txt");
    ofstream cout("output.txt");

	int N, M;
	cin >> N >> M;

	vector<int> H(N);

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	
	// Calling functions
	inizializza(N, H);
    for (int i = 0; i < M; i++) {
        char tipo;
        cin >> tipo;

        cout << endl << "iterazione " << i << ": ";

        if (tipo == 'Q') {
            int x;
            cin >> x;
            pair<int, int> risultato = chiedi(x);
            cout << risultato.first << ' ' << risultato.second;
        } else {
            int x, h;
            cin >> x >> h;
            cambia(x, h);
        }
    }
	return 0;
}

#endif