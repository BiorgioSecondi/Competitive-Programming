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

bool ordina(int N, vector<int> V, vector<int> &L) {
    bool ans = true;
    
    for(int i = N - 1 ; i >=0 ; i--){
        int end = i;
        while(V[i] <= V[i-1] and i>0) i--;
        L.pub( end - i + 1 );
        reverse( V.begin() + i, V.begin() + end + 1 );
    }

    for(int i = 0 ; i < N-1 ; i++) ans = ans && (V[i]<=V[i+1]);
    reverse(all(L));
    return ans;
}

#ifndef EVAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int main() {
        int N;
        ::cin >> N;
    
        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            ::cin >> V[i];
        }

        vector<int> L;
        bool risposta = ordina(N, V, L);

        if (risposta == true) {
            ::cout << "YES" << endl;

            int M = L.size();
            ::cout << M << endl;

            for (int i = 0; i < M; ++i) {
                ::cout << L[i] << " ";
            }
            ::cout << endl;

        } else {
            ::cout << "NO" << endl;
        }
}
#endif