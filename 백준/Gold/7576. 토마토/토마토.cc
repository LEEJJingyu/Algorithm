#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
    int x;
    int y;
    int time;
};

int map[1001][1001];

int main() {
    int n, m;
    int all = 0;
    int time = 0;
    bool error = false;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    cin >> m >> n;
    queue<Pos> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                q.push({i, j, 0});
            }
            if(map[i][j] == 0) {
                all++;
            }
        }
    }
    
    while(!q.empty()) {
        Pos pos = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = pos.x + dx[k];
            int ny = pos.y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == -1 || map[nx][ny] == 1) continue;
            map[nx][ny] = 1;
            all--;
            q.push({nx, ny, pos.time + 1});
            time = pos.time + 1;
        }
    }
    
    if(all > 0) {
        cout << -1 << endl;
    } else {
        cout << time << endl;
    }
    
    return 0;
}