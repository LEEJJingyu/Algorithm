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
int cnt = 0;
int arr1[1000001];
int arr2[1000001];
map<int, int> m;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    sort(arr2, arr2 + N);
    
    for (int i = 0; i < N; i++)
    {
        if (m.find(arr2[i]) == m.end())
        {
            m[arr2[i]] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << m[arr1[i]] << ' ';
    }
}