#include <bits/stdc++.h>

using namespace std;

#ifndef EVAL
    ifstream cin("i.txt");
    ofstream cout("o.txt");
#endif

vector<string> line;

int main() {
    int T;
    ::cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, M;
        ::cin >> N >> M;

        line.clear();
        line.resize(N);
        for (int i = 0; i < N; ++i)
            ::cin >> line[i];

        int ans = 1;
        int xmax=0,ymax=0,xmin=INT_MAX,ymin=INT_MAX;

        for(int i = 0 ; i<N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(line[i][j]=='1'){
                    xmax=max(j,xmax);
                    xmin=min(j,xmin);
                    ymax=max(i,ymax);
                    ymin=min(i,ymin);
                }
            }
        }
        if(ymin>ymax or xmin>xmax) ans=0;
        for(int i=ymin;i<=ymax;i++){
            for(int j=xmin;j<=xmax;j++){
                if(line[i][j]=='0'){
                    ans=0;
                    break;
                }
            }
            if(ans==0) break;
        }


        ::cout << ans << endl;
    }

    return 0;
}
