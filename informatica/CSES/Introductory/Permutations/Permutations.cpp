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
    vector<int> ans(N);
    if(N!=1 and N<=3){
        ::cout << "NO SOLUTION";
        return 0;
    }
    else if(N==4){
        ::cout << "2 4 1 3";
        return 0;
    }
    else if(N%2==1){
        for(int i = 2; i<=2*N;i+=2){
            ans[i%N]=i/2;
        }
    }
    else{
        for(int i = 2;i<=2*(N-1);i+=2){
            ans[i%(N-1)]=i/2;
        }
        ans[N-1]=N;
    }
    for (auto x: ans) ::cout << x << " ";
    return 0;
}