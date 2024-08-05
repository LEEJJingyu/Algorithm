#include<iostream>
#include<queue>
using namespace std;

pair<int, int> marbleR;
pair<int, int> marbleB;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
char board[10][10];
int N, M;

struct State {
    int rx, ry, bx, by, depth;
};

bool move(int &x, int &y, int dx, int dy, int &count) {
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O') {
        x += dx;
        y += dy;
        count++;
        if (board[x][y] == 'O') break;
    }
    return board[x][y] == 'O';
}

int bfs() {
    queue<State> q;
    q.push({ marbleR.first, marbleR.second, marbleB.first, marbleB.second, 0 });

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.depth >= 10) break;

        for (int i = 0; i < 4; ++i) {
            int nrx = cur.rx, nry = cur.ry, nbx = cur.bx, nby = cur.by;
            int rcnt = 0, bcnt = 0;

            bool redHole = move(nrx, nry, dx[i], dy[i], rcnt);
            bool blueHole = move(nbx, nby, dx[i], dy[i], bcnt);

            if (blueHole) continue;
            if (redHole) return cur.depth + 1;

            if (nrx == nbx && nry == nby) {
                if (rcnt > bcnt) {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (nrx == cur.rx && nry == cur.ry && nbx == cur.bx && nby == cur.by) continue;
            q.push({ nrx, nry, nbx, nby, cur.depth + 1 });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                marbleR = { i, j };
            else if (board[i][j] == 'B')
                marbleB = { i, j };
        }

    cout << bfs();
}
