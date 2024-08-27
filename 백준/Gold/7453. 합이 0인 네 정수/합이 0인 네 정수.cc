#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int n;
int A[4000];
int B[4000];
int C[4000];
int D[4000];
vector<int> twoAB;
vector<int> twoCD;
long long cnt = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    twoAB.reserve(n * n);
    twoCD.reserve(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            twoAB.push_back(A[i] + B[j]);
            twoCD.push_back(C[i] + D[j]);
        }
    }

    sort(twoCD.begin(), twoCD.end());

    for (int i : twoAB) {
        cnt += upper_bound(twoCD.begin(), twoCD.end(), -i) - lower_bound(twoCD.begin(), twoCD.end(), -i);
    }

    cout << cnt << endl;
    return 0;
}