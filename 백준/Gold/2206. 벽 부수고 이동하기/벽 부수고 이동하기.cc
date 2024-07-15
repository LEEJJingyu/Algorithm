#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<string> map(N);
    for(int i = 0; i < N; ++i) {
        cin >> map[i];
    }
    
    // 거리 정보를 저장할 3차원 벡터를 사용합니다. 세 번째 차원은 벽이 부서졌는지를 나타냅니다.
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, -1)));
    queue<tuple<int, int, int>> q;  // (x, y, 벽 부숨 여부)
    
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        auto [x, y, broken] = q.front();
        q.pop();
        
        if(x == N-1 && y == M-1) {
            cout << dist[x][y][broken] << '\n';
            return 0;
        }
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            
            if(map[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                // 다음 칸이 빈칸이고 이 상태로 방문한 적이 없다면
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            } else if(map[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == -1) {
                // 다음 칸이 벽이고 아직 벽을 부순 적이 없다면
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    
    cout << -1 << '\n';
    return 0;
}