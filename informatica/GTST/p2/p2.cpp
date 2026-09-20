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

#ifndef EVAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    int N,M;
    ::cin >> N >> M;

    vector<int> amici(N);
    fill(all(amici),0);


    // negativo quando gli devono tornare soldi, positivo altrimenti
    for(int i = 0 ; i < M ; i++){
        int A,B,W;
        ::cin >> A >> B >> W;
        amici[A]-= W;
        amici[B]+= W;
    }

    vector<pair<pii,int>> trans;
    
    for(int i = 1 ; i < N ; i++){
        if(amici[i-1]<0){
            trans.pub({{i,i-1},-amici[i-1]});
            amici[i]-= -amici[i-1];
            amici[i-1]+= -amici[i-1];
        }
        else if(amici[i-1]==0){
            continue;
        }
        else{
            trans.pub({{i-1,i}, amici[i-1]});
            amici[i] += amici[i-1];
            amici[i-1] = 0;
        }
    }

    :: cout << trans.size() << '\n';

    for(auto x : trans){
        ::cout << x.first.first << " " << x.first.second << " " << x.second << '\n';
    }

    return 0;
}