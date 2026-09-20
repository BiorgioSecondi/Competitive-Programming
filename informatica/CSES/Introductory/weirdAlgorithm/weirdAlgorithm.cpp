#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#else
    #define debug(x)
#endif

int main(){
    long long N;
    ::cin >> N;
    ::cout << N << " ";
    while (N != 1) {
        N = N%2==0 ? N/2 : 3*N+1;
        ::cout << N << " ";
    }
    return 0;
}