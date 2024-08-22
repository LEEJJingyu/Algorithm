#include<iostream>
#include<string>
using namespace std;

int N, M;
int height[500][500];
int dp[500][500];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int x, int y) {
    if (x == N - 1 && y == M - 1) 
        return 1;
    if (dp[x][y] != -1) 
        return dp[x][y];

    dp[x][y] = 0; 
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if (height[x][y] > height[nx][ny]) { 
                dp[x][y] += dfs(nx, ny);             }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> height[i][j];
            dp[i][j] = -1;
        }

    cout << dfs(0, 0) << '\n';
}
