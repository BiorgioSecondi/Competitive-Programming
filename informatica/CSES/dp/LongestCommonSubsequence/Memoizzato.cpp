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

struct node{
    int len;
    int choice;
    char pointer;
};

vector<vector<node>> dp;

node LCS(const vector<int> &A, const vector<int> &B, int i ,int j){

    if(dp[i][j].len != -1) return dp[i][j];
    // ::cout << "chiamata ricorsiva con i = " << i << " e j = " << j << endl;
    if(A[i-1] == B[j-1]){
        // ::cout << "primo caso" << endl;
        node temp = LCS(A,B,i-1,j-1);
        dp[i][j].len = 1 + temp.len;
        dp[i][j].choice = A[i-1];
        dp[i][j].pointer = 'D';
    }
    else{
        node first = LCS(A,B,i-1,j);
        node second = LCS(A,B,i,j-1);
        if(first.len < second.len ){
            // ::cout << "secondo caso" << endl;
            dp[i][j].pointer = 'L';
            dp[i][j].len = second.len;
            dp[i][j].choice = -1;
        }
        else{
            // ::cout << "terzo caso" << endl;
            dp[i][j].pointer = 'U';
            dp[i][j].len = first.len;
            dp[i][j].choice = -1;
        }
    }
    return dp[i][j];
}

int main(){
    ll n,m;
    ::cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);

    for(auto &a:A) ::cin >> a;
    for(auto &b:B) ::cin >> b; 

    node stock;
    stock.len = -1;
    dp.resize(n+1,vector<node>(m+1 , stock));

    node empty;
    empty.len = 0;
    empty.choice = -1;
    empty.pointer = 'E';
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = empty;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = empty;
    }

    node sol = LCS(A,B,n,m);
    int i = n;
    int j = m;
    int choice;
    char pointer;
    vector<int> seq;
    while (i > 0 and j > 0)
    {
        choice = dp[i][j].choice;
        pointer = dp[i][j].pointer;
        // ::cout << "iterazione while con i = " << i << " e j = " << j << endl;
        if(choice != -1) seq.push_back(choice);
        if(pointer == 'U') i--;
        else if(pointer == 'L') j--;
        else if(pointer == 'D'){
            i--;
            j--;
        }
    }
    reverse(all(seq));

    ::cout << sol.len << endl;
    for(auto x:seq) ::cout << x << " ";
    ::cout << endl;
}