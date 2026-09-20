#include <assert.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int minimo(int R, int G, int B){
  if (R<=B && R<=G) return R;
  if (G<=R && G<=B) return G;
  return B;
}

int massimo(int R, int G, int B){
  if (R>=B && R>=G) return 0;
  if (G>=R && G>=B) return 1;
  return 2;
}



int fungo(int A, int C, int r, int g, int b){
  return (A*((r*r)+(g*g)+(b*b)))+(C*minimo(r, g, b));
}

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  int testcase, T;
  int A, C, r, g, b;

  assert(1 == scanf("%d", &T));
  for (testcase = 0; testcase < T; testcase++) {
    assert(5 == scanf("%d %d %d %d %d", &A, &C, &r, &g, &b));
    int listozzo[3];
    string carlo_pesce[3]={"RED","GREEN","BLUE"};
    listozzo[0]=fungo(A,C,r+1,g,b);
    listozzo[1]=fungo(A,C,r,g+1,b);
    listozzo[2]=fungo(A,C,r,g,b+1);

    printf("%s\n", carlo_pesce[massimo(listozzo[0],listozzo[1],listozzo[2])].c_str());
  }
  return 0;
}
