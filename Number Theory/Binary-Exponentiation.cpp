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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;


ll binaryExpo(int base, int exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int32_t main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cout << binaryExpo(3, 10) << "\n";

    return 0;
}
