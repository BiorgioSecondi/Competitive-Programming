#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K) {
    vector<array<long long,3>> intervalli(M);
    for(int i = 0; i<M ; i++){
        intervalli[i][0]=L[i];
        intervalli[i][1]=R[i];
        intervalli[i][2]=K[i];
    }
    sort(intervalli.rbegin(),intervalli.rend());
    
    vector<int> prefix(N+1);
    fill(prefix.begin(),prefix.end(),1);
    int i = N-1;
    int j = 0;
    
    while(j<M and i>-1){
        if(intervalli[j][0]==i){

        }
        i--;
    }
    return 42;
}
