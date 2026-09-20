#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, K, sommozzo=0;
    int risposta=0;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(C.rbegin(),C.rend());
    risposta+=C[0];
    risposta-=C[N-1];

    vector<int> delta(N-1);
    for(int i=1;i<N;i++) delta[i-1]=C[i]-C[i-1];
    sort(delta.begin(),delta.end());


    for(int i=0;i<K-1;i++) risposta+=delta[i];


    cout << "Case #" << t << ": " << risposta << "\n";
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