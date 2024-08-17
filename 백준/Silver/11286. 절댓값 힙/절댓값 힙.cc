#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;
struct cmp
{
    bool operator()(int x,int y) {
        return abs(x) == abs(y) ?x>y :abs(x)>abs(y);
    }
};

priority_queue<int,vector<int>, cmp> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        if(t!=0)
            q.push(t);
        else
        {
            if (!q.empty()) {
                cout << q.top()<<'\n'; q.pop();
            }
            else
                cout << 0<<'\n';
        }
    }
}