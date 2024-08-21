#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

int N;
int arr[100002] = {0,};
int n = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N;

    fill(arr, arr + N + 1, N);
    arr[0] = 0;
    for (int i = 1; i * i <= N; i++) {
        int square = i * i;
        for (int j = square; j <= N; j++) {
            arr[j] = min(arr[j], arr[j - square] + 1);
        }
    }

    cout << arr[N];
}


