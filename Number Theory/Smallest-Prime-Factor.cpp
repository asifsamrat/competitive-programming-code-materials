#include<bits/stdc++.h>
using namespace std;

// Debuger start
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
// Debuger end

#define ll long long
const int INF = 1e9;
const int N = 1e5 + 10;

vector<int> spf(N + 10, 0);

void smallestPrimeFactorization(){
    for (int i = 1; i <= N; i++){
        spf[i] = i;
    }

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i){
            for (int j = i * i; j <= N; j += i){
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int32_t main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    smallestPrimeFactorization();

    // Printing the all prime factorization tc(Qlog(N));
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        while(n != 1){
            cout << spf[n] << " ";
            n /= spf[n]; 
        }
        cout << "\n";
    }

    return 0;
}
