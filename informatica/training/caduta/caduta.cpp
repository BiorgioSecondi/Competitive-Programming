#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())
#define pq priority_queue<int>

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

typedef enum {
	OK,
	RISOLTO,
	IMPOSSIBILE
} stato_t;

typedef struct {
	int domino1;
	int domino2;
} coppia_t;

vector<vector<int>> adj;

stato_t correggi(int N, int altezze[], coppia_t* scambio) {
	adj.clear();
	adj.resize(N);
	for(int i = 0 ; i < N ; i++){
		for(int j = i+1 ; j < altezze[i]+i and j < N; j++){
			adj[j].pub(i);
		}
	}

	if (N % 3 == 0) {
		// usa la sintassi scambio->campo invece di scambio.campo
		scambio->domino1 = 0;
		scambio->domino2 = 3;
		return RISOLTO;
	} else if (N % 3 == 1) {
		// stiamo dicendo che non era necessario risolvere
		return OK;
	} else {
		// stiamo dicendo che non era possibile risolvere
		return IMPOSSIBILE;
	}
}

#ifndef EVAL
	int main() {
		int N, *altezze;

		assert(1 == scanf("%d", &N));

		altezze = (int*) malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			assert(1 == scanf("%d", &altezze[i]));

		coppia_t scambio;
		stato_t stato = correggi(N, altezze, &scambio);

		if (stato == OK)
			printf("OK\n");
		else if (stato == IMPOSSIBILE)
			printf("IMPOSSIBILE\n");
		else
			printf("%d %d\n", scambio.domino1, scambio.domino2);

		free(altezze);
		return EXIT_SUCCESS;
	}
#endif