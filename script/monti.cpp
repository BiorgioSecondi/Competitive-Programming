#include <bits/stdc++.h>

using namespace std;

int main(){
    double beta=1.7;
    double x=1;
    double ans=0;
    for(int i = 0 ; i < 10000000; i++){
        ans += x;
        x = x-(pow(x,beta)/2);
    }
    cout << ans << endl;
    return 0;
}