#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solve(){

    int N;
    cin >> N;
    vector<int> V(N);
    for(int &x: V){
        cin >> x;
    }

    int risposta = V[0];

    for (int i=1; i<N ; i++){
        risposta=lcm(risposta,V[i]);
    }

    return risposta;
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}