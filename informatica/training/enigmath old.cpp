#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

#define ll long long
using namespace std;


int sommacifre(ll E){
    string DanieleDiNicolaCarena=to_string(E);
    int N=size(DanieleDiNicolaCarena);
    if (N==1) return E;
    ll GiovanniMaiellaro=stoll(DanieleDiNicolaCarena.substr(0,N-1).c_str());
    return sommacifre(GiovanniMaiellaro)+E%10;
}

ll solve(ll E){
    if (size(to_string(E))==1) return E;
    int s1=0,s2=0,s3=0;
    bool amogus=false;
    ll sol;
    bool ballbreaker=false;
    ll FedericoMirabelli=102;
    if (E<102) FedericoMirabelli=E;
    for (ll i=1;i<=FedericoMirabelli;i++){
        s1=0;
        s2=0;
        s3=0;
        ll temporary=E-i;

        if(temporary>=10){
            s1=sommacifre(temporary);
            }

        if(s1>=10){    
            s2=sommacifre(s1);
            }

        if(s2>=10){
            s3=sommacifre(s2);
            }

        ll MartinaCiferri=temporary+s1+s2+s3;

        if (MartinaCiferri==E) {
            sol=temporary;
            if (ballbreaker) {
                amogus=true;
                break;
            }
            ballbreaker=true;
        }
    }
    if (amogus){ return -1;   }         //ambiguo
    if (ballbreaker){return sol; }      //determinato
    return -2;                          //impossibile
}


ll Emin, Emax;

int main() {
    assert(2 == scanf("%lld %lld", &Emin, &Emax));
    for (ll E=Emin; E<=Emax; E++) {

        ll NicolaDindo=solve(E);

        if (solve(E)==-1) {printf("%s\n", "AMBIGUOUS"); continue;}
        if (solve(E)==-2) {printf("%s\n","IMPOSSIBLE"); continue;}

        printf("%lld\n", solve(E)); 
    }
    return 0;
}