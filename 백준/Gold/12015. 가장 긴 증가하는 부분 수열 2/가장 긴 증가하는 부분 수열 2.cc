#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        auto it = lower_bound(v.begin(), v.end(), num);
        if (it == v.end()) {
            v.push_back(num);
        }
        else {
            *it = num;
        }
    }

    cout << v.size();
}