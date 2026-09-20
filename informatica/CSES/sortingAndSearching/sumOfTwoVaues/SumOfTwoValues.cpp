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

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    #define debug(x) ::cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main(){
    ll n,x;
    ::cin >> n >> x;
    vector<pii> A;
    for(int i = 0 ; i < n ; i++){
        int temp;
        ::cin >> temp;
        A.pub({temp,i});
    }
    sort(all(A));
    ll i=0,j=n-1;
    ll sum = A[i].first + A[j].first;
    while (i<j-1)
    {
        if(sum > x) j--;
        else if(sum < x) i++;
        else if(sum == x) break;
        sum = A[i].first + A[j].first;
    }
    if(sum == x and i!=j){
        ::cout << A[i].second+1 << " " << A[j].second+1 << endl;
    }
    else{
        ::cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}