#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, C, M;
vector<tuple<int, int, int>> items;
int arr[2000] = {0};
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C >> M;
    for (int i = 0; i < M; i++) {
        int st, ed, weight;
        cin >> st >> ed >> weight;
        items.push_back({ed, st, weight});
    }

    sort(items.begin(), items.end());

    for (auto& item : items) {
        int ed = get<0>(item);
        int st = get<1>(item);
        int weight = get<2>(item);

        int mn = C;

        for (int i = st; i < ed; i++) {
            mn = min(mn, C - arr[i]);
        }

        int load = min(mn, weight);
        for (int i = st; i < ed; i++) {
            arr[i] += load;
        }

        ans += load;
    }

    cout << ans << '\n';
    return 0;
}
