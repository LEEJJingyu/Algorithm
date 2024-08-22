#include<iostream>
#include<string>
using namespace std;


int N, K;
int arr[1001][501] = { 0, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N>>K;
    arr[1][1] = 1;
    arr[2][1] = 2;
    arr[3][1] = 3;
    if (N / 2 < K) {
        cout << 0;
        return 0;
    }
    for (int i = 4; i <= N; i++) {
        arr[i][1] = i;
        for (int j = 2; j <= K; j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i - 2][j - 1]) % 1000000003;
        }
    }
    cout << arr[N][K]%1000000003;
}
