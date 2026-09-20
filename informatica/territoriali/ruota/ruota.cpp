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

        vector<int> R(N);
        for (int i = 0; i < N; ++i)
            cin >> R[i];

        int x = N;


        for(int i=1;i<N+1;i++){
            for(int j=0;j<N;j++){
                if(!(R[(j+i)%N]==R[j])){
                    x--;
                    break;
                }
            }
        }


        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}