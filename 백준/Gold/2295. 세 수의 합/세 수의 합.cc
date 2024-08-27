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
int arr[1001];
vector<int> two;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            two.push_back(arr[i]+arr[j]);
    sort(two.begin(), two.end());
    for (int i = N - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
        {
            int st = 0, ed = two.size()-1;
            while (st <= ed)
            {
                int mid = (st + ed) / 2;
                if (two[mid] == arr[i] - arr[j])
                {
                    cout << arr[i] << '\n';
                    return 0;
                }
                else if (two[mid] < arr[i] - arr[j])
                {
                    st = mid + 1;
                }
                else
                {
                    ed = mid - 1;
                }
            }

        }
}