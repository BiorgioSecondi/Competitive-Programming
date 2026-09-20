#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long Edo(long long n){
    long long S=1;
    return ((n-(S << (63-__builtin_clzll(n)))) << 1)+1;
}


int main() {
    long long Q;
    long long gamez;
    cin >> Q;
    
    for (long long i=0;i<Q;i++){
        cin >> gamez;
        cout << Edo(gamez) << "\n";
    }
    return 0;
}