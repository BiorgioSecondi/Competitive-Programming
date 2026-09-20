#include <stdio.h>
#include <assert.h>
#include <cmath>


int cacca(int c){
    int n;
    int m;
    int J;
}

int compra(int N, int M, int A, int B) {
    int sol=0;
    if (B<=A*M){
    while (N>=M){
        sol+=B;
        N-=M;
    }}
    else return N*A;
    if (B<=N*A) sol+=B; else sol+=A*N;
    return sol;
}

int main(int argc, char *argv[]) {
    FILE *fr, *fw;
    int N, M, A, B;

    printf("%d\n", argc);
    printf("%s\n",argv[0]);
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    fflush(stdout);

    //fr = fopen("input.txt", "r");
    //fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
