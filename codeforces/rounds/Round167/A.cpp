#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        int x,y;
        cin >> x;
        cin >> y;
        if(y > -2){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}