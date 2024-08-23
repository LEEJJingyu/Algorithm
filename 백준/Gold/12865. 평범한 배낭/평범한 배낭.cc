#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N, K;
pair<int, int> item[100];
int arr[100001] = {0,};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> item[i].first >> item[i].second;
    for (int i = 0; i < N; i++)
    {
        for (int j = K; j >=item[i].first; j--)
        {
            arr[j] = max(arr[j - item[i].first]+item[i].second,arr[j]);
        }
    }
    cout << arr[K];
}
