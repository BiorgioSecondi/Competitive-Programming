#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<string> g(n);
    vector<char> buf(n+5);
    for(int i=0;i<n;i++){
        scanf("%s", buf.data());
        g[i] = string(buf.data());
    }

    // choice[i][j] = 0 -> move down, 1 -> move right
    vector<vector<uint8_t>> choice(n, vector<uint8_t>(n, 0));
    vector<int> prevRank(n, 0), curRank(n, 0);

    prevRank[n-1] = 0; // diagonal containing only (n-1,n-1)

    vector<pair<int,int>> keyBuf; // (key, row)
    keyBuf.reserve(n);

    for(int d = 2*n - 3; d >= 0; d--){
        int lo = max(0, d - (n-1));
        int hi = min(d, n-1);
        keyBuf.clear();
        for(int i = lo; i <= hi; i++){
            int j = d - i;
            bool canDown  = (i + 1 < n);
            bool canRight = (j + 1 < n);
            int chosenRank; uint8_t dir;
            if(canDown && canRight){
                int rd = prevRank[i+1]; // (i+1, j)
                int rr = prevRank[i];   // (i, j+1)
                if(rd <= rr){ chosenRank = rd; dir = 0; }
                else        { chosenRank = rr; dir = 1; }
            } else if(canDown){
                chosenRank = prevRank[i+1]; dir = 0;
            } else {
                chosenRank = prevRank[i]; dir = 1;
            }
            choice[i][j] = dir;
            int c = g[i][j] - 'A';
            keyBuf.push_back({c * (n + 1) + chosenRank, i});
        }
        sort(keyBuf.begin(), keyBuf.end());
        for(int idx = 0; idx < (int)keyBuf.size(); idx++)
            curRank[keyBuf[idx].second] = idx;
        for(int i = lo; i <= hi; i++) prevRank[i] = curRank[i];
    }

    string ans; ans.reserve(2*n - 1);
    int i = 0, j = 0;
    while(true){
        ans.push_back(g[i][j]);
        if(i == n-1 && j == n-1) break;
        if(choice[i][j] == 0) i++; else j++;
    }
    printf("%s\n", ans.c_str());
}