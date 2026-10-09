#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;
const int N = 2e5 + 10;

vector<int> Graph[N], ReverseGraph[N];
vector<int> Component(N, -1);
vector<bool> Visited(N, false);
vector<int> Order;

int ComponentCount = 0;

void dfs1(int u) {
    Visited[u] = true;

    for (int v : Graph[u]) {
        if (!Visited[v]) {
            dfs1(v);
        }
    }
    //Can use stack
    Order.push_back(u);
}

void dfs2(int u, int id) {
    Component[u] = id;

    for (int v : ReverseGraph[u]) {
        if (Component[v] == -1) {
            dfs2(v, id);
        }
    }
}

void Kosaraju(int n) {
    for (int i = 1; i <= n; i++) {
        if (!Visited[i]) {
            dfs1(i);
        }
    }
    reverse(Order.begin(), Order.end());

    for (int u : Order) {
        if (Component[u] == -1) {
            dfs2(u, ComponentCount);
            ComponentCount++;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        Graph[i].clear();
        ReverseGraph[i].clear();
        Component[i] = -1;
        Visited[i] = false;
    }

    Order.clear();
    ComponentCount = 0;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        Graph[u].push_back(v);
        ReverseGraph[v].push_back(u);
    }

    Kosaraju(n);

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

    for (int i = 1; i <= TestCases; i++) {
        // cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}