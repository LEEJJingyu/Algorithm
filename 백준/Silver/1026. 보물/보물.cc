#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N;
int A[50], B[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    int s = 0;
    for (int i = 0; i < N; i++)
        s += A[i] * B[i];
    cout << s;
}
