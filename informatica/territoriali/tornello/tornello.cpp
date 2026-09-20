#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int solve() {
    int N;
    cin >> N;

    int risposta = 0;  // memorizza qui la risposta
    int dentro=0;
    int fuori=0;

    for (int i=0; i<N; i++) {
        int variazione;
        cin >> variazione;
        
        dentro+=variazione;
        fuori-=variazione;

        while(dentro<0){
            dentro++;
        }
        while(fuori<0){
            fuori++;
        }
    }

    risposta=dentro+fuori;

    return risposta;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}