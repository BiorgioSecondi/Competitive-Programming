#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for ( int t = 0; t < T ; t++){
        int N;
        cin >> N;
        vector<int> mov1(N);
        vector<int> mov2(N);
        for(int i=0;i<N;i++) cin >> mov1[i];
        for(int i=0;i<N;i++) cin >> mov2[i];

        pair<int,int> ans;

        for(int i=0; i<N;i++){
            if(mov1[i] != mov2[i]){
                if(mov1[i]>mov2[i]) ans.first+=mov1[i];
                else ans.second+=mov2[i];
            }
            else if(mov1[i]<0){
                if(ans.first<=ans.second){
                    ans.second--;
                }
                else ans.first--;
            }
            else{
                if(ans.first<=ans.second){
                    ans.first+=mov1[i];
                }
                else ans.first+=mov1[i];
            }
        }

        cout << min(ans.first,ans.second) << endl;
    }
}