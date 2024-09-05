#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


vector<pair<long long, int>> adj[100001]; // adj[cur] = {cost, nxt}
long long dist[100001];

long long lo = 1, hi;
int n, m, st, en; long long c;

bool solve(long long lim) {
    priority_queue < pair<long long, int>, vector<pair<long long, int>>,greater<pair<long long, int>> > pq;

    memset(dist, 0x3f, sizeof(dist));

    dist[st] = 0;
    pq.push({ 0, st });
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue;
        for (auto nxt : adj[cur.second]) {
            if (nxt.first > lim) continue;
            if (dist[nxt.second] > dist[cur.second]+nxt.first) {
                dist[nxt.second] = dist[cur.second]+nxt.first;
                pq.push({ dist[nxt.second], nxt.second});
            }
        }
    }

    if (dist[en] > c) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st >> en >> c;

    while (m--) {
        int u, v; long long cost;
        cin >> u >> v >> cost;
        adj[u].push_back({ cost, v });
        adj[v].push_back({ cost, u });
        hi = max(hi, cost);
    }

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (solve(mid)) hi = mid;
        else lo = mid + 1;
    }

    if (solve(lo)) cout << lo;
    else cout << -1;
}