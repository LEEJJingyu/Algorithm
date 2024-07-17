#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

char map[1001][1001];
int dist[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, p;
    cin >> N >> M >> p;
    
    vector<int> Si(p);
    for(int i = 0; i < p; i++) {
        cin >> Si[i];
    }
    
    vector<queue<pair<int, int>>> q(p);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] >= '1' && map[i][j] <= '9') {
                int player = map[i][j] - '1';
                q[player].push({i, j});
                dist[i][j] = 0;
            } else {
                dist[i][j] = -1;
            }
        }
    }
    
    bool expanded = true;
    while(expanded) {
        expanded = false;
        for(int player = 0; player < p; player++) {
            int size = q[player].size();
            for(int step = 0; step < Si[player] && !q[player].empty(); step++) {
                for(int s = 0; s < size; s++) {
                    int x, y;
                    tie(x, y) = q[player].front();
                    q[player].pop();
                    
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] == '.' && dist[nx][ny] == -1) {
                            map[nx][ny] = map[x][y];
                            dist[nx][ny] = dist[x][y] + 1;
                            q[player].push({nx, ny});
                            expanded = true;
                        }
                    }
                }
                size = q[player].size();
            }
        }
    }
    
    vector<int> result(p, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] >= '1' && map[i][j] <= '9') {
                result[map[i][j] - '1']++;
            }
        }
    }
    
    for(int i = 0; i < p; i++) {
        cout << result[i] << ' ';
    }
    
    return 0;
}
