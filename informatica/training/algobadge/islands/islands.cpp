#include <bits/stdc++.h>

#define MAXN 1000
using namespace std;
vector<vector<int>> M;

void dfs(int a, int b){
    if(M[a][b]!=0){
        //printf("\n chiamo una dfs in posizione (%d,%d), M qui valeva %d", a, b, M[a][b] );
        M[a][b]=0;
        //printf("\ndiramo la dfs");
        //printf("\nquesta dfs esplora e vede che M in (%d,%d) vale %d",a-1,b,M[(a-1)][b]);
        dfs((a-1),b);
        //printf("\nquesta dfs esplora e vede che M in (%d,%d) vale %d",a+1,b,M[(a+1)][b]);
        dfs((a+1),b);
        //printf("\nquesta dfs esplora e vede che M in (%d,%d) vale %d",a,b+1,M[a][(b+1)]);
        dfs(a,(b-1));
        //printf("\nquesta dfs esplora e vede che M in (%d,%d) vale %d",a,b-1,M[a][(b-1)]);
        dfs(a,(b+1));
    }
    return;
}

// input data
int R, C, sol=0;

int main() {


    //assorbiamo tutto l'input
    assert(2 == scanf("%d %d", &R, &C));
    M.resize(R+4, vector<int>(C+4, 0));
    for (int i=0;i<R+4;i++){
        for(int j=0;j<C+4;j++){
            if(j==1 or i==1 or j==C+2 or i==R+2 ) M[i][j]=1;
            if(j==0 or i==0 or j==C+3 or i==R+3 ) M[i][j]=0;
        }
    }
    for(int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            //printf("\n iterazione d'input %d-esima", C*i+j+1);
            cin >> M[i+2][j+2];
            //printf("\nsto prendendo l'input in posizione (%d,%d) cioè %d", i+2, j+2, M[i+2][j+2]);
        }
    }

    //dfs e abbiamo finito
    for (int a=1; a<R+4;a++){
        for (int b=1; b<C+4;b++){
            if(M[a][b]!=0){
                //printf("\nchiamo una dfs per la prima volta in posizione (%d,%d)", a, b);
                dfs(a,b);
                sol++;
            }
        }
    }

    printf("%d\n", sol-1); // print the result
    return 0;
}