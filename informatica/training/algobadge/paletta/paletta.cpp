#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pairvec pair<vector<int>,vector<int>>
#define vecpair vector<pair<int,int>>
#define pub push_back
#define MAXN 2097152 //la minima potenza di due più grande di maxn

vector<int> segtree;


void add(int k, int x) {
    k += segtree.size()/2;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
    segtree[k] = segtree[2*k]+segtree[2*k+1];
    }
    return;
}

int sum(int a, int b) {
    
    a += segtree.size()/2; b += segtree.size()/2;
    int s = 0;

    while (a <= b) {
    if (a%2 == 1) s += segtree[a++];
    if (b%2 == 0) s += segtree[b--];
    a /= 2; b /= 2;
    }

    return s;
}

ll count(int N, const vector<int> &W){


    segtree.resize((1 << 33-(__builtin_clz(N))));
    for(int i=0; i<segtree.size() ;i++) segtree[i]=0;

    ll ans=0;
    for(int i=0;i<W.size();i++){

        ans += sum(W[i]+1,N-1);
        add(W[i],1);

    }
    return ans;
}

pairvec split(int N, const int V[]){
    pairvec ans;
    for(int i=0; i<N;i++){
        if(i%2==0) ans.first.pub(V[i]);
        else       ans.second.pub(V[i]);
    }
    return ans;
}

long long paletta_sort(int N, int V[]) {


    ll ans = -1;

    pairvec trans = split(N,V);
    sort(trans.first.begin(),trans.first.end());
    sort(trans.second.begin(),trans.second.end());

    int current=0;
    bool breaker=true;
    for(int i=0; i<N; i++){
        if(i%2==0){
            if(trans.first[i/2]<current){
                breaker = false;
                break;
            }
            current = trans.first[i/2];
        }
        else{
            if(trans.second[(i-1)/2]<current){
                breaker = false;
                break;
            }
            current = trans.second[(i-1)/2];
        }
    }

    if(breaker){
        pairvec raw = split(N,V);
        ans = count(N,raw.first) + count(N,raw.second);
    }
    return ans;
}

#ifndef EVAL

#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int* V;
static long long int numero_ribaltamenti;

// Declaring functions
long long int paletta_sort(int N, int* V);

int main() {
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	

	// Reading input
	cin >> N;
	V = (int*)malloc(N * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		cin >> V[i0];
	}

	// Calling functions
	numero_ribaltamenti = paletta_sort(N, V);

	// Writing output
	cout << numero_ribaltamenti;
	return 0;
}

#endif