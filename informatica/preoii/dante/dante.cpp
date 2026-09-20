#include <bits/stdc++.h>

using namespace std;

int rimembra(int N, int K, vector<int> V){

    vector<int> zero;
    for(int i = 0; i < N ; i++){
        if(V[i]==0) zero.push_back(i+1);
    }
    int l = zero.size();
    if(K>=l) return N;
    if(l==N) return K;

    int ans = max(zero[K]-1,N-zero[l-K-1]);

    for(int i = 1; i+K < l ;i++){
        ans = max(ans,(zero[i+K])-(zero[i-1]+1));
    }

    return ans;
}

#ifndef EVAL

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int main(){
        int N, K; ::cin >> N >> K;

        vector<int> V(N);
        for(int &x: V) ::cin >> x;

        ::cout << rimembra(N, K, V) << "\n";
    } 

#endif