
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;
const int N = 2e5 + 10;

vector<int> Graph[N];
vector<int> Component(N, -1);
vector<int> tin(N, -1), low(N, 0);
vector<bool> inStack(N, false);
vector<int> st;

int timer = 0, ComponentCount = 0;

void dfs(int u) {
    tin[u] = low[u] = timer++;

    st.push_back(u);
    inStack[u] = true;

    for (int v : Graph[u]) {
        if (tin[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }

    // u is the root of an SCC
    if (low[u] == tin[u]) {
        while (true) {
            int v = st.back();
            st.pop_back();

            inStack[v] = false;
            Component[v] = ComponentCount;

            if (v == u) break;
        }

        ComponentCount++;
    }
}

void Tarjan(int n) {
    timer = 0;
    ComponentCount = 0;
    st.clear();

    for (int i = 1; i <= n; i++) {
        tin[i] = -1;
        low[i] = 0;
        Component[i] = -1;
        inStack[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (tin[i] == -1) {
            dfs(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        Graph[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
    }

    Tarjan(n);

    cout << ComponentCount << '\n';

    for (int i = 1; i <= n; i++) {
        cout << Component[i] << " \n"[i == n];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TestCases = 1;
    // cin >> TestCases;

    while (TestCases--) {
        solve();
    }

    return 0;
}