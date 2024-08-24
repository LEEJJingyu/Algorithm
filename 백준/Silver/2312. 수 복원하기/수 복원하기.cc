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
vector<bool> state(100001, true);
void func()
{
    state[1] = false;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (!state[i])continue;
        for (int j = i*i; j <= 100000; j+=i)
            state[j] =false;
    }
    for (int i = 2; i <= 100000; i++)
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
        for (int p : primes) {
            int cnt = 0;
            while (N%p==0)
            {
                N /= p;
                cnt++;
            }
            if (cnt > 0)
                cout << p << ' ' << cnt << '\n';
        }
    }
}