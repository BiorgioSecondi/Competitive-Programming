#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> W(N);

    vector<int> minimi(1);
    vector<int> massimi(1);

    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    int K1 = 0, K2 = INT_MAX;
    for(int i=0; i<N; i++){
        if(W[i]==-1){
            minimi.push_back(0);
            massimi.push_back(0);
            massimi[massimi.size()-2]+=W[i+1];
            continue;
        }
        minimi[minimi.size()-1]+=W[i];
        massimi[massimi.size()-1]+=W[i];
    }
    for(int i=0; i<minimi.size();i++){
        K1=max(K1,minimi[i]);
    }
    for(int i=0; i<massimi.size();i++){
        K2=min(K2,massimi[i]);
    }
        


    cout << "Case #" << t << ": " << K1 << " " << K2-1 << "\n";
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