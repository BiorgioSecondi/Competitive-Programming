#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> dist;
vector<bool> visitato;
vector<vector<int>> adiace;

void bfs(int start, int big){
    visitato.clear();
    visitato.resize(big);
    deque<int> pq;
    pq.push_front(start);
    dist[start]=1;
    while(!pq.empty()){
        if(!visitato[pq.back()]){
            int nodo=pq.back();
            pq.pop_back();
            visitato[nodo]=true;
            for(auto x: adiace[nodo]){
                if(!visitato[x]) dist[x]=min( dist[x] , dist[nodo]+1 );
                pq.push_front(x);
            }
        }
        else pq.pop_back();
    }
}

void solve(int t) {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> Z(A), X(B), Y(B);
    
    for (int i = 0; i < A; i++) {
        cin >> Z[i];
    }

    for (int i = 0; i < B; i++) {
        cin >> X[i] >> Y[i];
    }

    //mettiamo a posto le distanze
    dist.clear();
    for(int i=0; i<N ; i++){
        dist.push_back(INT_MAX);
    }

    //creiamo le liste di adiacenza
    adiace.clear();
    adiace.resize(N);
    for(int i=0;i<B;i++){
        adiace[X[i]].push_back(Y[i]);
        adiace[Y[i]].push_back(X[i]);
    }

    //calcoliamo le distanze
    for(int i=0;i<A;i++){
        bfs(Z[i],N);
    }

    //cerchiamo il massimo e abbiamo finito
    int num = 0; // memorizza qui il numero di interruttori
    int idx; // memorizza qui l'indice della lampadina
    for(int i=0;i<N;i++){
        if(num<dist[i]){
            num=dist[i];
            idx=i;
        }
    }

    cout << "Case #" << t << ": " << idx << " " << num << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}