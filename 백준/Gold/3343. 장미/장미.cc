#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;
long long n, a, b, c, d;
long long ans = 9223372036854775807;

long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a,a);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> c >> d;

    if (a * d > b * c) {
        swap(a, c);
        swap(b, d);
    }

    long long lst = lcm(a, c);
    for (long long i = 0; i < (lst / a); i++) {
        long long cost = i * b;
        if (n - i * a > 0) cost += ((n - i * a-1) / c+1) * d;
        ans = min(ans, cost);
    }

    cout << ans;
}