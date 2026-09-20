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

int main() {
//  uncomment the following lines if you want to read/write from files
    #ifndef EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    int Q;
    cin >> Q;

    vector<int> P(Q), T(Q);
    for (int i = 0; i < Q; i++) {
        cin >> P[i] >> T[i];
    }


    vector<pll> automobili(N);


    for (int i = 0; i < Q; i++) {
        for(int j = 0 ; j < N ; j++){
            automobili[j]={(A[j]*T[i]*T[i])+(B[j]*T[i])+C[j],j+1};
        }
        sort(all(automobili));
        cout << automobili[P[i]].second << endl;
    }

    return 0;
}
