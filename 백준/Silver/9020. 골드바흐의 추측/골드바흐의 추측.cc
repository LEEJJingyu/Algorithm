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
int T, N;

vector<int> primes;
vector<bool> state(1000001, true);
void func()
{
    state[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (!state[i])continue;
        for (int j = i * i; j <= 1000000; j += i)
            state[j] = false;
    }
    for (int i = 2; i <= 1000000; i++)
        if (state[i])primes.push_back(i);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    func();
    while (T--)
    {
        cin >> N;
        int gap = N;
        for (int p : primes) {
            if (p > N / 2)break;
            if (state[N - p]&&gap>N-2*p)
            {
                gap = N - 2 * p;
            }
        }
        cout << (N-gap)/2<<' '<<(N + gap) / 2 << '\n';
    }
}