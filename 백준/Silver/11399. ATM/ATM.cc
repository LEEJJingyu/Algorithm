#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N;
int arr[1000];
int t = 0;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        t += arr[i];
        ans += t;
    }
    cout << ans;
}
