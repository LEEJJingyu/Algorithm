#include <iostream>
using namespace std;

struct Cctv {
    int x, y, type;
};

int N, M;
int map[8][8];
int monitored[8][8];
Cctv cctvs[8];
int cctv_num = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int directions[4] = { 1, 2, 4, 8 };
int mn;

void apply_cctv(int x, int y, int dir, bool state) {
    for (int d = 0; d < 4; ++d) {
        if (dir & directions[d]) {
            int nx = x, ny = y;
            while (true) {
                nx += dx[d];
                ny += dy[d];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 6)
                    break;
                if (state)
                    monitored[nx][ny]++;
                else
                    monitored[nx][ny]--;
            }
        }
    }
}

int calculate() {
    int blind_spot = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (map[i][j] == 0 && monitored[i][j] == 0)
                ++blind_spot;
    return blind_spot;
}

void search(int index) {
    if (index == cctv_num) {
        mn = min(mn, calculate());
        return;
    }
    Cctv c = cctvs[index];
    switch (c.type) {
        case 1:
            for (int i = 0; i < 4; ++i) {
                apply_cctv(c.x, c.y, directions[i], true);
                search(index + 1);
                apply_cctv(c.x, c.y, directions[i], false);
            }
            break;
        case 2:
            for (int i = 0; i < 2; ++i) {
                apply_cctv(c.x, c.y, directions[i] | directions[(i + 2) % 4], true);
                search(index + 1);
                apply_cctv(c.x, c.y, directions[i] | directions[(i + 2) % 4], false);
            }
            break;
        case 3:
            for (int i = 0; i < 4; ++i) {
                apply_cctv(c.x, c.y, directions[i] | directions[(i + 1) % 4], true);
                search(index + 1);
                apply_cctv(c.x, c.y, directions[i] | directions[(i + 1) % 4], false);
            }
            break;
        case 4:
            for (int i = 0; i < 4; ++i) {
                apply_cctv(c.x, c.y, directions[i] | directions[(i + 1) % 4] | directions[(i + 2) % 4], true);
                search(index + 1);
                apply_cctv(c.x, c.y, directions[i] | directions[(i + 1) % 4] | directions[(i + 2) % 4], false);
            }
            break;
        case 5:
            apply_cctv(c.x, c.y, 15, true); // 모든 방향 감시
            search(index + 1);
            apply_cctv(c.x, c.y, 15, false);
            break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    mn = N * M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6) {
                cctvs[cctv_num++] = { i, j, map[i][j] };
            }
        }
    }
    // 초기화
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            monitored[i][j] = 0;
        }
    }
    search(0);
    cout << mn;
}