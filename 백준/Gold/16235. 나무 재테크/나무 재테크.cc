#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int board[12][12];
int S2D2[12][12];
int dx[8] = { 1, 0, -1, 1, 0, -1, 1, -1 };
int dy[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
vector<int> trees[12][12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        fill(board[i], board[i] + N, 5);
        for (int j = 0; j < N; j++) {
            cin >> S2D2[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back(z);
    }

    for (int year = 0; year < K; year++) {
        // Spring and Summer
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (trees[i][j].empty()) continue;

                sort(trees[i][j].begin(), trees[i][j].end());

                vector<int> alive;
                int dead_nutrients = 0;

                for (int age : trees[i][j]) {
                    if (board[i][j] >= age) {
                        board[i][j] -= age;
                        alive.push_back(age + 1);
                    } else {
                        dead_nutrients += age / 2;
                    }
                }

                board[i][j] += dead_nutrients;
                trees[i][j] = alive;
            }
        }

        // Fall
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int age : trees[i][j]) {
                    if (age % 5 == 0) {
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = i + dx[dir];
                            int ny = j + dy[dir];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                                trees[nx][ny].push_back(1);
                            }
                        }
                    }
                }
                // Winter
                board[i][j] += S2D2[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += trees[i][j].size();
        }
    }

    cout << ans << "\n";
    return 0;
}