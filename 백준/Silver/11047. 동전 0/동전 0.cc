#include<iostream>
#include<string>
using namespace std;

int N, K;
int coin[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];
    int cnt = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        while (coin[i] <= K && K > coin[i - 1])
        {
            K -= coin[i];
            cnt++;
        }
    }
    cnt += K;
    cout << cnt;
}
