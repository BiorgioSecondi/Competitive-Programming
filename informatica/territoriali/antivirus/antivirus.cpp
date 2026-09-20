#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void solve(int t) {
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;

    int M;
    cin >> M;

    string F1, F2, F3, F4;
    cin >> F1 >> F2 >> F3 >> F4;

    // scrivi in queste variabili la risposta
    int p1, p2, p3, p4;
    bool ballbreaker=false;

    for(int i=0;i<N1;i++){
        for(int j=0;j<N2;j++){
            for(int k=0;k<N3;k++){
                for(int w=0;w<N4;w++){
                    if(
                        F1.substr(i,M)==F2.substr(j,M) and
                        F2.substr(j,M)==F3.substr(k,M) and
                        F3.substr(k,M)==F4.substr(w,M)
                    ){
                        ballbreaker=true;
                        p1=i;
                        p2=j;
                        p3=k;
                        p4=w;
                        break;
                    }
                }
                if(ballbreaker) break;
            }
            if(ballbreaker) break;
        }
        if(ballbreaker) break;
    }

    cout << "Case #" << t << ": " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}