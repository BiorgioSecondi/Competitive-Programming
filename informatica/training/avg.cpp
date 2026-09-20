#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, K, somma=0;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i){
        cin >> P[i];
        somma+=P[i];
    }
    int ans = 0;
    int NK=N*K;
    int i=0;

    if (NK<somma){
        sort(P.begin(), P.end());
        while (somma>NK){
            somma-=P[N-1-i]-1;
            i++;
    }
    ans=i;
    }
    else if(NK>somma) ans=1;
    
    
    cout << ans << endl;

    return 0;
}