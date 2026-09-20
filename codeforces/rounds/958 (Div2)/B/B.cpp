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

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    /*#ifndef ONLINE_JUDJE
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif*/
    
    int T;
    cin >> T;
    for(int testcase = 0; testcase<T;testcase++){
        int n,ones=0,zeros=0;
        cin >> n;
        vector<char> lungo;
        char first;
        cin >> first;
        lungo.pub(first);
        if(lungo.back()=='0') zeros++;
        if(lungo.back()=='1') ones++;
        for(int i=1;i<n;i++){
            char temp;
            cin >> temp;
            if(temp=='0' and temp == lungo.back()) continue;
            lungo.pub(temp);
            if(lungo.back()=='0') zeros++;
            if(lungo.back()=='1') ones++;
        }
        if(ones>zeros) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0; 
}