#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<long long> H(N);
        for (int i = 0; i < N; ++i)
            cin >> H[i];

        long long x = -1;
        long long prom=0;


        for (int i=1; i < N-1; ++i){
            long long delta=min(H[i]-H[i+1],H[i]-H[i-1]);
            if(delta>prom){
                prom=delta;
                x=i;
            }
        }


        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}