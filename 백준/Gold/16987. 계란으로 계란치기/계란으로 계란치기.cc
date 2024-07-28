#include <iostream>
using namespace std;

pair<int, int> egg[8];
int N, cnt;
bool broken[8] = {false};

int break_egg(int left, int right) {
    int t = 0;
    egg[left].first -= egg[right].second;
    egg[right].first -= egg[left].second;
    if (egg[left].first <= 0) { broken[left] = true; t++; }
    if (egg[right].first <= 0) { broken[right] = true; t++; }
    return t;
}

void restore_egg(int left, int right) {
    if (egg[left].first <= 0) { broken[left] = false; }
    if (egg[right].first <= 0) { broken[right] = false; }
    egg[left].first += egg[right].second;
    egg[right].first += egg[left].second;
}

void func(int k, int n) {
    if (k == N) {
        if (cnt < n) cnt = n;
        return;
    }
    if (broken[k]) {
        func(k + 1, n);
        return;
    }

    bool isOne = true;
    for (int i = 0; i < N; i++) {
        if (i == k || broken[i]) continue;
        isOne = false;
        int broken_count = break_egg(k, i);
        func(k + 1, n + broken_count);
        restore_egg(k, i);
    }

    if (isOne) {
        func(N, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> egg[i].first >> egg[i].second;
    }
    cnt = 0;
    func(0, 0);
    cout << cnt;
    return 0;
}