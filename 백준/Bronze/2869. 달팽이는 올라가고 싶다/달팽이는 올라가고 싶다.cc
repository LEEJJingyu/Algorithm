#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
using namespace std;
int A, B, V;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> V;
    int ans = (V - A) / (A - B) + 1+ ((V - A) % (A - B)!=0);
    cout << ans;
}