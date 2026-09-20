#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pqi=priority_queue<int>;
using pqll=priority_queue<ll>;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

#pragma GCC optimize("O3")

struct DSU{
    vector<int> g;
    vector<int> dim;
    DSU(int N){
        g.resize(N);
        dim.resize(N);
        for(int i = 0 ; i < N ; i++){
            g[i]=i;
            dim[i]=1;
        }
    }
    int find(int a){
        if(g[a]==a) return a;
        g[a]=find(g[a]);
        return g[a];
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a==b) return;
        g[a]=b;
        dim[b]+=dim[a];
        return;
    }
};

long long viaggia(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> V, vector<int> W) {

    vector<vector<pii>> adj(N);
    for(int i = 0 ; i < M ; i++){
        adj[B[i]].pub({T[i],A[i]});
    }

    vector<pii> dtree(N);
    for(int i =0 ; i < N ; i++){
        dtree[i]={INT_MAX,i};
    }

    vector<bool> visited(N,false);
    vector<ll> distance(N,INT_MAX);
    distance[N-1]=0;
    dtree[N-1]={0,N-1};
    priority_queue<pii> q;
    q.push({0,N-1});

    while (!q.empty()){
        int nodo = q.top().second;
        q.pop();
        if(visited[nodo]) continue;
        visited[nodo]=true;
        for(auto figlio : adj[nodo]){
            if (distance[nodo] + figlio.first < distance[figlio.second]){
                distance[figlio.second] = distance[nodo] + figlio.first;
                dtree[figlio.second] = {figlio.first, nodo};
                q.push({-distance[figlio.second],figlio.second});
            }
        }
    }
    /*for(int i = 0 ; i < V.size();i++){
        if(V[i]!=-1) dtree[i]={W[i],V[i]};
    }*/
    ll ans=0;
    int curr=0;
    DSU path(N);
    int cont = 0;
    for(int i = 0; i<N; i++) if(V[i] == -1) path-merge(dtree[i].second, i);
    while(curr!=N-1){
        assert(++cont <=2*N);
        cerr << curr << ' ';
        if(V[curr]!=-1){
            ans += W[curr];
            int prev=curr;
            curr = V[curr];
            V[prev]=-1;
            path.merge(prev,curr);
        }
        else{
            int prev=curr;
            curr = path.find(curr);
            ans += distance[prev]-distance[curr];
            ans+= dtree[curr].first;
            curr = dtree[curr].second;
            path.merge(prev,curr);
        }
    }
    cerr << '\n' << cont << '\n';
    return ans;
}

#ifndef EVAL
    int main() {
        ifstream cin("input.txt");
        ofstream cout("output.txt");
        int N, M;
        cin >> N >> M;

        vector<int> A(M), B(M), T(M), V(N), W(N);
        for (int i = 0; i < N; i++)
            cin >> V[i];
        for (int i = 0; i < N; i++)
            cin >> W[i];
        
        for (int i = 0; i < M; i++)
            cin >> A[i] >> B[i] >> T[i];
        
        cout << viaggia(N, M, A, B, T, V, W) << '\n';
    }
#endif

