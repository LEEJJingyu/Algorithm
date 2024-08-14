#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_map<long long, int> m;
    long long number;
    for (int i = 0; i < N; i++) {
        cin >> number;
        m[number]++;
    }

    int mx = 0;
    long long ans = pow(2,62);

    for (auto& p : m) {
        if (p.second > mx) {
            mx = p.second;
            ans = p.first;
        } else if (p.second == mx && p.first < ans) {
            ans = p.first;
        }
    }

    cout << ans << '\n';
    return 0;
}
