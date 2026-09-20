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

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int N, K, D;
    std::cin >> N >> K >> D;

    std::vector<int> A(N);
    for (int& x : A) std::cin >> x;

    std::vector<int> B = execute(N, K, D, A);
    for (std::size_t i = 0; i < B.size(); ++i) {
        std::cout << B[i];
        if (i + 1 < B.size()) std::cout << " ";
    }
    std::cout << std::endl;
}
