// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define node pair<int,pair<int,int>>
#define explosion second.second
#define cost second.first
#define index first
//#define int long long
#define MAXM 100000
#define MAXN 10000


// input data
int N, M, T;
vector<int> A(MAXM), B(MAXM), C(MAXM), E(MAXM);
vector<bool> processed(MAXN);
vector<int> distanze(MAXN);

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N >> M >> T;
    for (int i=0; i<M; i++)
        cin >> A[i] >> B[i] >> C[i] >> E[i];

    vector<vector<node>> adj(N);
    for(int i=0; i<M;i++){
        adj[A[i]].push_back({B[i],{C[i],E[i]}});
    }

    priority_queue<pair<int,int>> q;

    for (int i = 1; i <= N; i++) distanze[i] = INT_MAX;
    for (int i = 0; i <= N; i++) processed[i] = false;
    distanze[0] = 0;

    q.push({0,0});
    while (!q.empty()) {
        if(processed[N-1]) break;
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.index, w = u.cost;
            if (u.explosion==1 and distanze[a]+w > T) {
                continue;
            }
            if (distanze[a]+w < distanze[b]) {
                distanze[b] = distanze[a]+w;
                q.push({-distanze[b],b});
            }
        }
    }
    if(distanze[N-1]==INT_MAX) distanze[N-1]=-1;
    cout << distanze[N-1] << endl; // print the result
    return 0;
}
