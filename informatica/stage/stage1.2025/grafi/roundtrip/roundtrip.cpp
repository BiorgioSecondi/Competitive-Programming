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

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int end, int start){
    queue<int> q;
    q.push(start);
}

int main(){
    int N,M;
    ::cin >> N >> M;
    adj.resize(N);
    visited.resize(N);
    fill(all(visited),false);

    vector<pii> edge(M);

    for(int i = 0 ; i < M ; i++){
        ::cin >> edge[i].first >> edge[i].second;
        adj[edge[i].first].pub(edge[i].second);
        adj[edge[i].second].pub(edge[i].first);
    }

}
