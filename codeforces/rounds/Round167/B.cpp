#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T;t++){
        string a,b;
        cin >> a;
        cin >> b;

        int ans = a.length() + b.length();
        int init=0;

        for(int i=0;i < a.length();i++){
            for(int j=init; j < b.length();j++){
                if(b[i]==a[j]){
                    ans--;
                    init = j+1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}