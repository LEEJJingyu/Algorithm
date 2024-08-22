#include<iostream>
#include<string>
using namespace std;

int N;
int arr[16];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    if (N % 2)
    {
        cout << 0;
        return 0;
    }
    arr[0] = 1;
    arr[1] = 3;
    for (int i = 2; i <= N / 2; i++) {
        arr[i] = arr[i - 1] * 3;
        for (int j = 2; j <= i; j++)
            arr[i] += arr[i - j] * 2;

    }
    cout << arr[N / 2];
}
