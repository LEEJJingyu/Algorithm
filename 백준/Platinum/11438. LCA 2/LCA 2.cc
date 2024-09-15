#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100001;
const int LOG = 17;

vector<int> adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];

void dfs(int cur, int par) {
    parent[cur][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (parent[cur][i - 1] == -1) break;
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (int nxt : adj[cur]) {
        if (nxt != par) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = parent[a][i];
        }
    }

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(&parent[0][0], &parent[0][0] + sizeof(parent) / sizeof(int), -1);
    fill(depth, depth + N + 1, 0);

    dfs(1, -1); 

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}
