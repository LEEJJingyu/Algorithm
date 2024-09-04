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


int p[100001];
pair<int, int> x[100001];
pair<int, int> y[100001];
pair<int, int> z[100001];

vector<tuple<int, int, int>> e; // e = {cost, u, v};

int find(int cur) {
    if (p[cur] < 0) return cur;
    return p[cur] = find(p[cur]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(p, p + 100001, -1);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int cx, cy, cz;
        cin >> cx >> cy >> cz;
        x[i] = { cx, i };
        y[i] = { cy, i };
        z[i] = { cz, i };
    }

    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);

    for (int i = 1; i < n; i++) {
        e.push_back({ abs(x[i - 1].first - x[i].first), x[i - 1].second, x[i].second });
        e.push_back({ abs(y[i - 1].first - y[i].first), y[i - 1].second, y[i].second });
        e.push_back({ abs(z[i - 1].first - z[i].first), z[i - 1].second, z[i].second });
    }

    sort(e.begin(), e.end());

    int cnt = 0, sum = 0;
    for (auto nxt : e) {
        int cost, u, v;
        tie(cost, u, v) = nxt;
        if (!is_diff_group(u, v)) continue;
        sum += cost;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << sum;
}