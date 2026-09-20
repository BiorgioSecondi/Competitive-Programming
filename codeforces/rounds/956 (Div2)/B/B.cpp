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
    for(int i = 0; i<T;i++){

        string ans = "yes";

        int N,M;
        cin >> N >> M;
        vector<int> RA(N);
        vector<int> CA(M);
        vector<int> RB(N);
        vector<int> CB(M);
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                char temp;
                cin >> temp;
                int num = temp - '0';
                RA[j]+=temp; RA[j] %= 3;
                CA[k]+=temp; CA[k] %= 3;
            }
        }
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                char temp1;
                cin >> temp1;
                int num1 = temp1 - '0';
                RB[j]+=temp1; RB[j] %= 3;
                CB[k]+=temp1; CB[k] %= 3;
            }
        }

        for(int j = 0; j < N;j++){
            if(RA[j] != RB[j]){
                ans = "no";
                break;
            }
        }
        for(int j = 0; j < M;j++){
            if(CA[j] != CB[j]){
                ans = "no";
                break;
            }
        }


        cout << ans << "\n";
    }
    return 0; 
}




#ifndef EVAL //ONLINE_JUDJE

//main...

#endif