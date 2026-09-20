#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    string sol="-1";


    if (N==2) sol="51";
    if (N>=3){
        if (N%3==0){
            sol="";
            for (int i=0;i<N;i++) sol+="1";
    }
        if (N%3==1){
            sol="55";
            for (int i=0;i<N-2;i++) sol+="1";
    }
        if (N%3==2){
            sol="5";
            for (int i=0;i<N-1;i++) sol+="1";
    }}

    cout << sol << endl; // print the result
    return 0;
}
