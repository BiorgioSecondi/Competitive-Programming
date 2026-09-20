#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

vector<int> ranking(int N, int T, vector<int> X, vector<int> V, vector<int> P) {
    vector<int> ans(N,0);
    /*vector<pair<int,int>> sinistra;
    vector<pair<int,int>> destra;


    for(int i = 0 ; i < N ; i++){
        if(V[i]==-1){
            sinistra.push_back({X[i],i});
        }
        else{
            destra.push_back({X[i],i});
        }
    }

    //calcoliamo per ogni formica quante ne deve sorpassare per essere felice

    for(int i = 0 ; i < destra.size() ; i++){
        int id_destra = destra[i].second;

        int sorpasso = P[id_destra]-i; 
        // vuole avere #sorpasso formiche alla sua sinistra, ovvero essere alla stessa posizione dell'elemento numero sorpasso in sinistra
        if(id_destra > P[id_destra]){
            ans[id_destra]=0;
            continue;
        }else if(sorpasso == sinistra.size()){
            ans[id_destra] = max(0,T-(sinistra[sorpasso-1].first/2) + (X[id_destra]/2));
        }else if(sorpasso > sinistra.size()){
            ans[id_destra] = 0 ;
        }else if(sorpasso==0){
            ans[id_destra] = max(0,min((sinistra[sorpasso].first/2)-(X[id_destra]/2), T));
        }else{
            ans[id_destra] = max(0,min((sinistra[sorpasso].first/2) - (sinistra[sorpasso-1].first/2), T-(sinistra[sorpasso-1].first/2) + (X[id_destra]/2)));
        }
    }

    for(int i = 0 ; i < sinistra.size() ; i++){
        int id_sinistra = sinistra[i].second;

        int sorpasso = P[id_sinistra]-i;
        if(sorpasso < 0){
            ans[id_sinistra] = 0 ;
            continue;
        }
        // vuole avere #sorpasso formiche alla sua sinistra, ovvero essere alla posizione sorpasso in V
        if(id_sinistra < P[id_sinistra]){
            ans[id_sinistra]=0;
            continue; 
        }else if(sorpasso == destra.size()){
            ans[id_sinistra] = max(0,T+(destra[sorpasso-1].first/2) - (X[id_sinistra]/2));            
        }else if(sorpasso == 0){
            ans[id_sinistra] = max(0,min(T-(destra[sorpasso].first/2)+(X[id_sinistra]/2), T));
        }else{
            ans[id_sinistra] = max(0,min((destra[sorpasso-1].first/2)-(destra[sorpasso].first/2), T - (X[id_sinistra]/2) + (sinistra[sorpasso-1].first/2)));
        }
    }*/
    vector<pair<pair<int,int>,pair<int,int>>> cum(N);
    for(int i = 0 ; i < N ; i++){
        cum[i].first.first = X[i];
        cum[i].first.second = i;
        cum[i].second.first = P[i];
        cum[i].second.second = V[i]; 
    }
    for(int i = 1 ; i <= T ; i++){
        for(int j = 0 ; j < N ; j++){
            cum[j].first.first+=cum[j].second.second;
        }
        sort(all(cum));
        for(int i = 0 ; i < N ; i++){
            if(cum[i].second.first==i) ans[cum[i].first.second]++;
        }
    }    
    return ans;
}

#ifndef EVAL
    int main() {
        ifstream cin("input.txt");
        ofstream cout("output.txt");

        int N, T;
        cin >> N;
        cin >> T;

        vector<int> X(N), V(N), P(N);

        for (int i = 0 ; i < N ; i++ )
            cin >> X[i];
        for (int i = 0 ; i < N ; i++ )
            cin >> V[i];
        for (int i = 0 ; i < N ; i++ )
            cin >> P[i];

        vector<int> risposta = ranking(N, T, X, V, P);

        for (int x: risposta)
            cout << x << ' ';
        cout << endl;
    }
#endif 