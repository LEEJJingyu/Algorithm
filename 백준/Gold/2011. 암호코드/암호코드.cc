#include<iostream>
#include<string>
using namespace std;

int arr[5001] = { 0, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if (s[0] == '0') {
        cout << 0;
        return 0;
    }

    int n = s.size();
    arr[0] = 1; 
    arr[1] = 1; 
    for (int i = 2; i <= n; i++) {
        int oneDigit = s[i - 1] - '0';
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if (oneDigit >= 1 && oneDigit <= 9) {
            arr[i] = arr[i - 1];
        }

        if (twoDigits >= 10 && twoDigits <= 26) {
            arr[i] = (arr[i] + arr[i - 2]) % 1000000;
        }
    }

    cout << arr[n];
}
