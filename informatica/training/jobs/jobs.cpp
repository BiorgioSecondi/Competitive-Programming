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
#define lim 2900

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#ifndef EVAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

int main() {

    int N, M;
    ::cin >> N >> M;
    vector<int> P(N);
    vector<int> T(N);
    for (int i = 0; i < N; ++i) ::cin >> T[i];
    for (int i = 0; i < N; ++i) ::cin >> P[i];

    int max=0;
    double ratio=0;
    ll mod=0;
    for(int i = 0 ; i < N ; i++){
        if(P[i]/T[i]>ratio){
            ratio = P[i]/T[i];
            max=i;
        }
    }
    if(M>lim){
        mod = (ll)((ll)P[max]*(ll)((M-lim)/T[max]));
        M-=(mod/P[max])*T[max];
    }

    int length=501;
    vector<ll> dp(length, 0);

    for (int pos=0 ; pos<M+1 ; ++pos){
        for (int att=0 ; att<N ; ++att){
            ll futuro = dp[(pos+T[att])%length];
            ll presente = dp[pos%length]+P[att];

            dp[(pos+T[att])%length] = futuro < presente ? presente : futuro;
        }
    }

    ::cout << mod+dp[M%length] << "\n";

    return 0;
}
