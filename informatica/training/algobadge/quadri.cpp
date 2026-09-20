int quadri(int N, long long M, int V[]) {
    int B=0;
    long long sommozzo=0;
    int testacoda=0;
    int sol=N;

    for (int i=0;i<N;i++){
        sommozzo+=(long long)V[i];
        B++;
        while (sommozzo>M){
            sommozzo-=(long long)V[testacoda];
            testacoda++;
            B--;
            sol = B<sol ? B:sol;
        }
    }

    return sol;
}
