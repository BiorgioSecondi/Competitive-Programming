#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N;
        cin >> N;

        int operazioni = 1;


        while(N>2){
            if(N%2==1){
                N++;
                operazioni++;
            }
            else{
                N/=2;
                operazioni++;
            }
        }


        cout << "Case #" << test << ": ";
        cout << operazioni << endl;
    }

    return 0;
}