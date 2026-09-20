#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pqi = priority_queue<int>;
using pqll = priority_queue<ll>;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define sz(a) ((int)a.size())

#pragma GCC optimize("O3")

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

vector<complex<double>> FFT(const vector<complex<double>> &A, int n){ //vincolo statico: n deve essere una potenza di 2

    //assertm(n > 0,"n non è positivo");
    if(n==1){
        return A;
    }
    //assertm(n%2 == 0,"n non è una potenza di 2");

    complex<double> omega = exp(((2.0*M_PI)/n) * 1i);
    vector<complex<double>> A0(n/2);
    vector<complex<double>> A1(n/2);

    for(int i = 0; i < n; i += 2){
        A0[i/2] = A[i];
        A1[i/2] = A[i+1];
    }

    A0 = FFT(A0,n/2);
    A1 = FFT(A1,n/2);

    vector<complex<double>> ans(n);
    complex<double> temp = 1.0;

    for(int i = 0; i < n/2; i++){
        complex<double> D = temp * A1[i];
        ans[i] = A0[i] + D;
        ans[i + n/2] = A0[i] - D;
        temp *= omega;
    }

    return ans;
}

vector<complex<double>> INV_FFT(const vector<complex<double>> &A, int n){
    auto B = FFT(A,n);
    reverse(B.begin()+1 , B.end());
    for(auto &b:B) b /= n;
    return B;
}

vector<int> LIN_CONV(vector<int> A, vector<int> B, int n){
    A.resize(2*n, 0);
    B.resize(2*n, 0);

    vector<complex<double>> TA(2*n);
    vector<complex<double>> TB(2*n);
    for(int i = 0; i < 2*n; i++){
        TA[i] = complex<double>(A[i], 0.0);
        TB[i] = complex<double>(B[i], 0.0);
    }

    TA = FFT(TA, 2*n);
    TB = FFT(TB, 2*n);

    vector<complex<double>> Tans(2*n);
    for(int i = 0; i < 2*n; i++){
        Tans[i] = TA[i] * TB[i];
    }

    auto Cans = INV_FFT(Tans,2*n);

    vector<int> ans(2*n);
    for(int i = 0; i < 2*n; i++){
        ans[i] = int(round(Cans[i].real()));
    }

    return ans;
}

int main(){
    ll n;
    ::cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i = 0 ; i < n ; i++){
        ::cin >> A[i];
    }
    for(int i = 0 ; i < n ; i++){
        ::cin >> B[i];
    }
    vector<int> C = LIN_CONV(A, B, n);
    for(auto c:C) ::cout << c << " ";
    ::cout << endl;

    return 0;
}