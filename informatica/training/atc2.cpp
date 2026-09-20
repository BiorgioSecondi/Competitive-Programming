#include <bits/stdc++.h>
using namespace std;

vector<int16_t> martina, dindo;

int find(int x) {
    while (x != dindo[x]) x = dindo[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (martina[a] < martina[b]) swap(a,b);
    martina[a] += martina[b];
    dindo[b] = a;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int N; cin >> N;

    vector<pair<int16_t, int16_t>> daniele;
    vector<pair<int32_t, pair<int16_t, int16_t>>> ciferri;
    for (int16_t i = 0; i < N; i++) {
        for (int16_t j = 0; j < N; j++) {
            char maiellaro; cin >> maiellaro;
            if (maiellaro == 'T') {
                int16_t M = daniele.size();
                for (int16_t nicola = 0; nicola < M; nicola++) {
                    ciferri.push_back({(i-daniele[nicola].first)*(i-daniele[nicola].first)+(j-daniele[nicola].second)*(j-daniele[nicola].second), {nicola, M}});
                }
                daniele.push_back({i, j});
            }
        }
    }
    sort(ciferri.begin(), ciferri.end());

    int16_t M = daniele.size();
    martina.resize(M, 1);
    dindo.resize(M);
    iota(dindo.begin(), dindo.end(), 0);

    int32_t risposta = 0;
    for (auto filippo: ciferri) {
        if (!same(filippo.second.first, filippo.second.second)) {
            unite(filippo.second.first, filippo.second.second);
            risposta += filippo.first;
        }
    }

    cout << risposta << '\n';
    return 0;
}
