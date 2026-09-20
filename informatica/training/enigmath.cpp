#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

#define ll long long
using namespace std;


int sommaCiferri(ll E){
    string DanieleDiNicolaCarena=to_string(E);
    int N=size(DanieleDiNicolaCarena);
    if (N==1) return E;
    ll GiovanniMaiellaro=stoll(DanieleDiNicolaCarena.substr(0,N-1).c_str());
    return sommaCiferri(GiovanniMaiellaro)+E%10;
}

vector<int> massencoding(ll Emin, ll Emax){
    ll j=0;
    ll lower=Emin-102;
    if (Emin<102) lower=0;
    vector<int> mappa(lower-Emax+1);
    for (ll i=lower;i<=Emax;i++){
        if (size(to_string(i))==1) {mappa[j]=i; j++;}
        else{
            long int s1=0,s2=0,s3=0;

            if(i>=10){
                s1=sommaCiferri(i);
            }

            if(s1>=10){    
                s2=sommaCiferri(s1);
            }

            if(s2>=10){
                s3=sommaCiferri(s2);
            }

            mappa[j]=i+s1+s2+s3;
            j++;
        }
    }
    return mappa;
}


ll Emin, Emax;

int main() {
    assert(2 == scanf("%lld %lld", &Emin, &Emax));
    vector<int> encoded=massencoding(Emin,Emax);
    ll lower=Emin-102;
    if (Emin<102) lower=0;
    bool amogus=false;

    for (ll E=Emin; E<=Emax; E++) {
        ll decoded=0;
        int counter=0;
        for (ll x=0;x<=Emax+102-Emin;x++){
            if(encoded[x]==E) {counter++; decoded=(ll)x+lower;}
            if(counter>=2) {amogus=true; break;}
        }
        if (amogus){printf("%s\n", "AMBIGUOUS"); continue;}
        if (counter==0){printf("%s\n","IMPOSSIBLE"); continue;}
        printf("%lld\n", decoded); 
    }
    return 0;
}