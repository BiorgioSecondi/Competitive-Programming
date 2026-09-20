#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

long long viaggia(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> V, vector<int> W) {
    ll ans=0;
    vector<ll> distance(N);
    vector<int> visited(N);
    fill(all(visited),0);
    fill(all(distance),INT64_MAX);
    vector<vector<pair<int,int>>> adj(N);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i = 0 ; i < M ; i++){
        adj[A[i]].push_back({T[i],B[i]});
    }

    distance[N-1]=0;
    pq.push({0,N});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        if(visited[node]>0) continue;
        visited[node]++;
        for(auto x: adj[node]){
            int dest = x.second;
            ll lungh = distance[node]+x.first;
            distance[dest]=min(lungh,distance[dest]);
            pq.push({lungh,dest});
        }
    }

    

    return ans;
}

#ifndef EVAL

ifstream cin("input.txt");
ofstream cout("output.txt");

int main() {
    int N, M;
    ::cin >> N >> M;

    vector<int> A(M), B(M), T(M), V(N), W(N);
    for (int i = 0; i < N; i++)
        ::cin >> V[i];
    for (int i = 0; i < N; i++)
        ::cin >> W[i];
    
    for (int i = 0; i < M; i++)
        ::cin >> A[i] >> B[i] >> T[i];
    
    ::cout << viaggia(N, M, A, B, T, V, W) << '\n';
}

#endif