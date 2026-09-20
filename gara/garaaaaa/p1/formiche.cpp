#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

vector<int> ranking(int N, int T, vector<int> X, vector<int> V, vector<int> P) {
    vector<int> ans(N);
    vector<pair<int,int>> sinistra;
    vector<pair<int,int>> destra;


    for(int i = 0 ; i < N ; i++){
        if(V[i]==-1){
            sinistra.push_back({X[i],i});
        }
        else{
            destra.push_back({X[i],i});
        }
    }

    //calcoliamo per ogni formica quante ne deve sorpassare per essere felice

    for(int i = 0 ; i < destra.size() ; i++){
        int id_destra = destra[i].second;
        if(P[id_destra] < V[id_destra]){
            ans[id_destra] = 0;
            continue;
        }
        int sorpasso = P[id_destra]-i;
        if(sorpasso >= N+1){
            ans[id_destra]=0;
            continue;
        }

        int tempo = abs((X[sorpasso-1]-X[id_destra])/2);
        if (sorpasso = N){
            ans[id_destra] = T-tempo;
        }
        else{
            ans[id_destra]=min(T-tempo,(X[sorpasso]-X[id_destra])/2);
        }
    }

    for(int i = 0 ; i < sinistra.size() ; i++){
        int id_sinistra = sinistra[i].second;
        if(P[id_sinistra] > V[id_sinistra]){
            ans[id_sinistra] = 0;
            continue;
        }
        int sorpasso = P[id_sinistra]-i;
        if(sorpasso >= N+1){
            ans[id_sinistra]=0;
            continue;
        }

        int tempo = abs((X[sorpasso-1]-X[id_sinistra])/2);
        if (sorpasso = N){
            ans[id_sinistra] = T-tempo;
        }
        else{
            ans[id_sinistra]=min(T-tempo,(X[sorpasso]-X[id_sinistra])/2);
        }
    }
    return ans;
}

#ifndef EVAL
    int main() {
        ifstream cin("input.txt");
        ofstream cout("output.txt");
        ios::sync_with_stdio(false);
        ::cin.tie(0); // Remove these two lines in interactive problems.

        int N, T;
        assert(::cin >> N);
        assert(cin >> T);

        vector<int> X(N), V(N), P(N);

        for (int& x : X)
            assert(cin >> x);
        for (int& x : V)
            assert(cin >> x);
        for (int& x : P)
            assert(cin >> x);

        vector<int> risposta = ranking(N, T, X, V, P);

        for (int x: risposta)
            ::cout << x << ' ';
        ::cout << endl;
    }
#endif 