#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pqi = priority_queue<int>;
using pqll = priority_queue<ll>;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

//#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
ifstream cin("input.txt");
ofstream cout("output.txt");
#endif


int main(){
    ll N;
    ::cin >> N;
    vector<int> A(N);
    for (auto &x: A) ::cin >> x;
    
    stack<pair<int,int>> S;

    for(int i = 0 ; i < N ; i++){
        while(!S.empty() and A[i]<=S.top().first){
            S.pop();
        }
        if(S.empty()){
            ::cout << "0 ";
        }
        else{
            ::cout << S.top().second+1 << " ";
        }
        S.push({A[i],i});
    }
    return 0;
}