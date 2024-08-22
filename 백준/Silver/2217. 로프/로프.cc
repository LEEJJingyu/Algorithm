#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;
int rope[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }
    sort(rope, rope + N);
    int mx = 0;
    for (int i = 0; i < N; i++)
    {
        mx = max(rope[i]*(N-i), mx);
    }
    cout << mx;
}
