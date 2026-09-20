#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#define maxn 1000000000

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("\ncaso %d",T);
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        vector<int> B(N);
        for (int i = 0; i < N; ++i)
            cin >> B[i];

        int x = 0;
        int a=0,b=0;

        while(max(a,b)<N){
            if(A[a]==B[b]){
                a++;
                b++;
                x++;
                printf("\ni due elementi nelle posizioni %d e %d sono uguali, quindi aggiungo uno a x",a,b);
                continue;
            }
            if(A[a]<B[b]){
                a++;
                printf("\naumento b");
                continue;
            }
            if(A[a]>B[b]){
                b++;
                printf("\naumento a");
                continue;
            }
        }

        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}