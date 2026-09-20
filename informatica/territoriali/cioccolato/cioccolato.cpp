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
        long long N, M, K;
        cin >> N >> M >> K;

        long long risposta = 0;

        if(K>max(N-M,M-N)){
            K-=max(N-M,M-N);
            M=min(M,N);
            N=min(M,N);
            risposta=(N-K%2-K/2)*(N-K/2);
        }
        else risposta=(max(M,N)-K)*min(M,N);
        


        cout << "Case #" << test << ": ";
        cout << risposta << endl;
    }

    return 0;
}