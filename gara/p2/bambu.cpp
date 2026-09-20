#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

vector<long long> taglia(int N, int M, int Q, vector<vector<long long>> A, vector<long long> K) {

    vector<pair<int,int>> tagli;
    long long SOM=0;
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            SOM+=A[i][j];
        }
    }
    vector<long long> ans(Q,SOM);

    for(auto &x: A) sort(allr(x));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            while(A[i][j]==A[i][j+1]){ 
                j++;
            }
            if(A[i][j]==0) continue;
            if(j<M-1) tagli.push_back({j+1,A[i][j]-A[i][j+1]});
            else tagli.push_back({M,A[i][j]});
        }
    }
    sort(all(tagli));

    for(int i = 0 ; i < Q ; i++){
        for(auto x : tagli){
            if(K[i]==0) break;
            else if(K[i]< x.second){
                ans[i] -= x.first *K[i];
                K[i]=0; 
            }
            else{
                ans[i]-=x.first*x.second;
                K[i]-=x.second;
            }

        }
        ans[i]-=K[i]*M;
    } 
    return ans;
}

#ifndef EVAL
    int main() {
        ifstream cin("input.txt");
        ofstream cout("output.txt");
        int N, M, Q; cin >> N >> M >> Q;
        vector A(N, vector<long long>(M, 0));
        vector<long long> K(Q, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < Q; i++) {
            cin >> K[i];
        }

        auto R = taglia(N, M, Q, A, K);

        for (long long x : R) cout << x << ' ';
        cout << endl;

        return 0;
    }
#endif