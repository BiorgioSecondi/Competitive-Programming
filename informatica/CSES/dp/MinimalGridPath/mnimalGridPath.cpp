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

struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    ::cin.tie(NULL);

    int n;
    ::cin >> n;

    vector<vector<char>> data(n,vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            ::cin >> data[i][j];
        }
    }

    vector<vector<bool>> dp(n,vector<bool>(n,false));
    dp[0][0] = true;

    vector<char> ans;

    for(int k = 0 ; k < 2*n - 1; k++){

        char m = 'Z'+1;

        // ::cout << "iterazione con k = " << k << endl;

        for(int i = max(0,k - n + 1) ; i < min(k+1,n)  ; i++){

            int j = k-i;
            // ::cout << "iterazione per il minimo con (i,j)=" << "(" << i << "," << j << ")" << endl;

            // troviamo il minimo 
            if(dp[i][j]) m = min(m,data[i][j]);

        }

        ans.push_back(m);

        for(int i = max(0,k - n + 1) ; i < min(k+1,n) ; i++){
            int j = k-i;

            // iteriamo su tutti i livelli e queueiamo i prossimi candidati

            // ::cout << "iterazione per la queue con (i,j)=" << "(" << i << "," << j << ")" << endl;
            if(dp[i][j] and data[i][j]==m){
                if(i < n-1){
                    dp[i+1][j] = true;
                }
                if(j < n-1){
                    dp[i][j+1] = true;
                }
            }
        }
    }

    // for(int i = 0 ; i < n ; i ++){
    //     for(int j = 0 ; j < n ; j++){
    //         ::cout << dp[i][j] << " ";
    //     }
    //     ::cout << endl;
    // }

    for(auto c:ans) ::cout << c;
    ::cout << endl;
}