#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pqi=priority_queue<int>;
using pqll=priority_queue<ll>;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");   
#endif

int main(){
    int N;
    ::cin >> N;
    vector<int> M(N-1);
    for(int i = 0 ; i < N-1; i++){
        ::cin >> M[i];
    }
    sort(all(M));
    for(int i=0;i<N;i++){
        if(M[i]!=i+1){
            ::cout << i+1;
            break;
        }
    }
    return 0;
}