#include <iostream>
#include <vector>
using namespace std;

bool board[10][10];
int paper[5] = { 5, 5, 5, 5, 5 };
int mn = 25;

bool canPlace(int si, int sj, int size) {
    if (si + size > 10 || sj + size > 10) return false;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (!board[si + i][sj + j]) return false;
    return true;
}

void place(int si, int sj, int size, bool status) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[si + i][sj + j] = status;
}

void dfs(int si, int sj, int cnt) {
    if (cnt >= mn) return;

    while (si < 10 && !board[si][sj]) {
        sj++;
        if (sj == 10) {
            sj = 0;
            si++;
        }
    }

    if (si == 10) {
        mn = cnt;
        return;
    }

    for (int size = 5; size >= 1; size--) {
        if (paper[size - 1] > 0 && canPlace(si, sj, size)) {
            paper[size - 1]--;
            place(si, sj, size, false);
            dfs(si, sj, cnt + 1);
            place(si, sj, size, true);
            paper[size - 1]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> board[i][j];

    dfs(0, 0, 0);

    if (mn == 25) mn = -1;
    cout << mn << '\n';
    return 0;
}
