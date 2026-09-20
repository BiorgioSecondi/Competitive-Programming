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
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

#ifndef ONLINE_JUDGE
    #define debug(x) ::cout << #x << " = " << x << endl;
#endif 

int main(){
    ll N,M;
    ll K;
    ::cin >> N >> M >> K;
    vector<int> A(N); //appartamenti
    vector<int> B(M); //grandezze desiderate
    for(auto &x : A) ::cin >> x;
    for(auto &x : B) ::cin >> x;
    sort(all(A));
    sort(all(B));

    ll i=0,j=0;
    ll ans=0;
    while(i<N and j<M){
        if(A[i]>=B[j]-K and A[i]<=B[j]+K){
            i++;
            j++;
            ans++;
        }
        else if(A[i]<B[j]-K){
            i++;
        }
        else if(A[i]>B[j]+K){
            j++;
        }
    }
    ::cout << ans << endl;
    return 0;
}