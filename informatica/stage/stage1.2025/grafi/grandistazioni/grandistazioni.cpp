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

//#pragma GCC optimize("O3")

struct DSU{
    vector<int> g;
    // vector<int> dim;
    DSU(int N){
        g.resize(N);
        // dim.resize(N);
        for(int i = 0 ; i < N ; i++){
            g[i]=i;
            // dim[i]=1;
        }
    }
    int find(int a){
        return g[a] == a ? a : g[a] = find(g[a]); 
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        // if(dim[a]>dim[b]) swap(a,b);
        g[a]=b;
        // dim[b]+=dim[a];
        return;
    }
};

long long viaggia(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> V, vector<int> W) {

    vector<vector<pii>> adj(N);
    for(int i = 0 ; i < M ; i++){
        adj[B[i]].pub({T[i],A[i]});
    }

    vector<int> dtree(N);
    for(int i =0 ; i < N ; i++){
        dtree[i]=i;
    }

    vector<bool> visited(N,false);
    vector<ll> distance(N,INT64_MAX);
    distance[N-1]=0;
    dtree[N-1]=N-1;
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
                dtree[figlio.second] = nodo;
                q.push({-distance[figlio.second],figlio.second});
            }
        }
    }

    ll ans=0;
    int curr=0;
    DSU path(N);
    fill(all(visited),false);

    // vector<int> high(N);
    // for(int i = 0 ; i < N ; i++) high[i]=i;
    
    int cont = 0;
    while(curr!=N-1){
        assert(++cont <= 2*N);
        //cerr << curr << ' ';
        int succ;
        if(visited[curr]){
            ans += distance[curr] - distance[high[path.find(curr)]];
            curr = high[path.find(curr)];
            continue;
        }
        else if(V[curr]==-1){
            succ = dtree[curr];
            path.merge(succ,curr);
            high[path.find(curr)]=succ;
            ans += distance[curr] - distance[succ];
            visited[curr]=true;
        }
        else{
            succ = V[curr];
            V[curr]=-1;
            ans+=W[curr];
        }
        curr = succ;
    }
    //cerr << '\n' << cont << '\n';
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

