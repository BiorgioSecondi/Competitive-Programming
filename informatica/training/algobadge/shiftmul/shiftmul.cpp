#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define prim 1000000007
#define ll long long

vector<int> shift(ll n, ll d, const vector<int> &A){
    vector<int> ans(n);
    for(int i=0 ; i<n ; i++){
        ans[(ll)(((ll)(i+d))%n)]=A[i]%prim;
    }
    return ans;
}

vector<int> mul(int n,const vector<int> &A, const vector<int> &B){
    vector<int> ans(n);
    for(int i=0; i<n;i++){
        ans[i]=((ll)((ll)(A[i]%prim)*(ll)(B[i]%prim)))%prim;
    }
    return ans;
}

vector<int> execute(int N, int K, int D, vector<int> A) {
    if(K==1) return A;
    vector<int> aux = execute(N,K/2,D,A);
    vector<int> B = mul(N,aux,shift(N,(ll)((K/2)*D),aux));
    if(K%2!=0) B = mul(N,B,shift(N,(ll)((K-1)*D),A));
    return B;
}