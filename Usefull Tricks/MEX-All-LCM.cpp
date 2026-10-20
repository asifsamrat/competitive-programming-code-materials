#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;
const int LIMIT = 4256233;

void solve() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> curr, next;
    set<ll> st;
    for (int i = 0; i < n; i++) {
        next.clear();
        if (arr[i] > LIMIT) {
            curr.clear();
            continue;
        }

        next.push_back(arr[i]);
        st.insert(arr[i]);
        for (auto v: curr) {
            ll lcm = (v / __gcd(v, arr[i])) * arr[i];
            if (lcm > LIMIT) {
                continue;
            }
            if (next.back() != lcm)next.push_back(lcm);
            st.insert(lcm);
        }
        curr.swap(next);
    }

    int ans = 1;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (*it != ans) break;
        ans++;
    }
    cout << ans << "\n";
}

int32_t main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TestCases = 1;
    cin >> TestCases;

    for (int i = 1; i <= TestCases; i++) {
        // cout << "Case "<< i << ": ";
        solve();
    }
    return 0;
}
