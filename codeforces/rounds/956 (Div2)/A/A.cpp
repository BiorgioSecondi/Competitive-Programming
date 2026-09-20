#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())
#define pq priority_queue<int>

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    /*#ifndef ONLINE_JUDJE
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif*/
    
    int T;
    cin >> T;
    for(int i = 0; i<T;i++){
        int n;
        cin >> n;
        for(int j=1;j<=n;j++){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0; 
}




