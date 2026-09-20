#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#define maxn 100000

using namespace std;

vector<string> dp;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int A, B;
        cin >> A >> B;

        string X="";

        int massimo = (sqrt(1+8*(A+B))-1)/2;
        if(massimo*(massimo+1)==2*(A+B)){
            for(int i=0; i<massimo ; i++){
                X.push_back('1');
            }
            while(B>massimo){
                B-=massimo;
                X[massimo-1]='2';
                massimo--;
            }
            X[B-1]='2';
        }
        else X="IMPOSSIBILE";


        cout << "Case #" << test << ": " << X << endl;
    }

    return 0;
}