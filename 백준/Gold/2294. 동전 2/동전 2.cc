#include<iostream>
#include<string>
using namespace std;
int N, K;
int coin[101];
int arr[10001] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];
    fill(arr, arr + K+1, (1<<27));
    arr[0] = 0;
    
    for(int i=0;i<N;i++)
    for (int j = coin[i]; j <= K; j++)
    {
        arr[j] = min(arr[j - coin[i]]+1,arr[j]);
    }
    if (arr[K] == (1 << 27))arr[K] = -1;
    cout << arr[K];
}
