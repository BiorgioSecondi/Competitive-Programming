#include <bits/stdc++.h>
using namespace std;
#define MAXN 500000
#pragma gcc optimize("O0")
#define ll long long

int N, M, i;
vector<ll> A(MAXN), C;
vector<int>E(MAXN);

int main() {

    cin >> N >> M;
    for (i=0; i<N; i++)
        cin >> A[i];
    for (i=0; i<M; i++)
        cin >> E[i];
    A.resize(N);
    E.resize(M);
    C = A;
    sort(A.begin(), A.end());

    for (i=0; i<M; i++) {
        bool breakato = 0;
        bool nonso = 0;
        if(C[E[i]]>0) {
            nonso = 1;
            N++;
        }
3
        vector<ll> somme(N);
        somme[0+nonso]=C[E[i]];
        if(C[E[i]]==A[0])
            somme[1+nonso]=somme[0+nonso]+A[N-nonso-1];
        else
            somme[1+nonso]=somme[0+nonso]+A[0];

        bool fede = 0;
        for (int j = 2+nonso; j < N; ++j) {
            //int boh = A[j&1? N-(j<<1) : (j<<1)];
            int boh;
            if(j&1) 
                boh = A[N-((j+1)/2)-nonso-fede];
            else
                boh  = A[j/2];
            if (boh == C[E[i]]) {
                fede = 1;
                if(j&1) 
                    boh = A[N-((j+1)/2)-nonso-fede];
            }
            
            somme[j]=somme[j-1]+boh;
            if (((somme[j] > somme[j-2]) == !(j&1))^nonso) {
                cout << somme[j-2] << ' ';
                breakato = 1;
                break;
            }
        }
        if(!breakato)
            cout << somme[N-1] << ' ';
        N -= nonso;
    }
    cout << '\n';
    return 0;
}
