#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
using namespace std;
int M, N;

bool state[1000001] = {0,};
void func() {
    state[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (state[i]) continue;
        for (int j = i*i; j <= N; j += i)
            state[j] = true;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    func();
    for (int i = M; i <= N; i++) {
        if (!state[i]) cout << i << '\n';
    }
}