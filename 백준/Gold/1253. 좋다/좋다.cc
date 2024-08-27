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
int arr[2000];
bool check[2000] = {0,};
int cnt = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int k = 0; k < N; k++) {
        int i = 0, j = N - 1;
        while (i < j) {
            if (i == k) {
                i++;
                continue;
            }
            if (j == k) {
                j--;
                continue;
            }
            if (arr[i] + arr[j] == arr[k]) {
                cnt++;
                break;
            }
            else if (arr[i] + arr[j] < arr[k]) {
                i++;
            }
            else {
                j--;
            }
        }
    }
    cout << cnt;
}