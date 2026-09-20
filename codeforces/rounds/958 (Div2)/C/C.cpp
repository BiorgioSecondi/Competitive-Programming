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
        unsigned long long n;
        cin >> n;
        bitset<64> seq(n);
        int grand = 64 - __builtin_clz(n);
        if(seq.count()==1){
            cout << "1\n" << n << "\n";
            continue;
        }
        cout << seq.count()+1 << '\n';

        for(int i = grand;i>=0;i--){
            if(seq[i]){
                bitset temp = seq;
                temp.flip(i);
                if(temp.any()){
                    cout << temp.to_ullong() << " ";
                }
            }
        }
        cout << seq.to_ullong() << " ";

        cout << '\n';
    }
    return 0; 
}