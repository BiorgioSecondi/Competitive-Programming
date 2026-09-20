#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <cmath>

#define ll long long
using namespace std;

vector<ll> listone;

int maxint(int A, int B, int C, int M){
    if (A%M>=B%M && A%M>=C%M) return A;
    if (B%M>=A%M && B%M>=C%M) return B;
    return C;
}

int maxll(int A, int B, int C, int M){
    if (A%M>=B%M && A%M>=C%M) return A;
    if (B%M>=A%M && B%M>=C%M) return B;
    return C;
}

int occulta(int N, int M, int Biorgio){
    if (N==1) return maxint(3,6,9,M);
    int primo=occulta(N-1, M, Biorgio*10+3);
    int secondo=occulta(N-1, M, Biorgio*10+6);
    int terzo=occulta(N-1, M, Biorgio*10+9);
    listone.push_back(primo);
    return listone[0];
}

int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%lld ", occulta(N, M, 0));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}