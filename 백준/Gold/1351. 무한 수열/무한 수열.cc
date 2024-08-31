#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long N;
int P,Q;
unordered_map<long long, long long> m1;

long long solve(long long x) {
	if (x == 0) return 1;
	if (m1[x]) return m1[x];

	m1[x] = solve(x / P) + solve(x / Q);
	return m1[x];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> P >> Q;
	cout << solve(N);
}