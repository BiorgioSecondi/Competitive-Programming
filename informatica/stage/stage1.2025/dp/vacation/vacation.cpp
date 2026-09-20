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

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    int N;
    ::cin >> N;    

    vector<vector<int>> A(N);

    for(int i = 0 ; i < N ; i++){
        int a,b,c;
        ::cin >> a >> b >> c;
        A[i].push_back(a);
        A[i].push_back(b);
        A[i].push_back(c);
    }

    for(int i = 1 ; i < N ; i++){
        A[i][0] = max(A[i-1][1]+A[i][0], A[i-1][2]+A[i][0]);
        A[i][1] = max(A[i-1][0]+A[i][1], A[i-1][2]+A[i][1]);
        A[i][2] = max(A[i-1][1]+A[i][2], A[i-1][0]+A[i][2]);
    }
    int ans=0;
    int p1= A[N-1][0];
    int p2= A[N-1][1];
    int p3= A[N-1][2];
    ans = max(p1,max(p2, p3));

    ::cout << ans;

    return 0; 
}
