#include <bits/stdc++.h>
using namespace std;

void main(){
    int N;
    int var=0;
    cin >> N;
    int res=0;
    for(int i=0;i<N;i++){
      cin >> var;
      res+=var;
    }
    float res2=(float)res/N;
    printf("%d %lf", res, res2 );
} 