#include <iostream>
#include <queue>
using namespace std;

struct coordinate {
    int z, x, y;
};

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

bool next_permutation(int arr[], int n) {
    int i = n - 1;
    while (i > 0 && arr[i - 1] >= arr[i])
        i--;

    if (i <= 0)
        return false;

    int j = n - 1;
    while (arr[j] <= arr[i - 1])
        j--;

    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;

    reverse(arr, i, n - 1);

    return true;
}

bool cube[5][4][5][5];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int mn = 100000;
int per[5] = { 0, 1, 2, 3, 4 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력 받기
    for (int k = 0; k < 5; k++)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                cin >> cube[k][0][i][j];

    // 각 층의 회전 배열 생성
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                cube[k][1][j][4 - i] = cube[k][0][i][j];
                cube[k][2][4 - i][4 - j] = cube[k][0][i][j];
                cube[k][3][4 - j][i] = cube[k][0][i][j];
            }
    }

    do {
        for (int r1 = 0; r1 < 4; r1++) {
            for (int r2 = 0; r2 < 4; r2++) {
                for (int r3 = 0; r3 < 4; r3++) {
                    for (int r4 = 0; r4 < 4; r4++) {
                        for (int r5 = 0; r5 < 4; r5++) {
                            int rotations[5] = { r1, r2, r3, r4, r5 };
                            if (!cube[per[0]][rotations[0]][0][0] || !cube[per[4]][rotations[4]][4][4])
                                continue;

                            queue<coordinate> q;
                            q.push({ 0, 0, 0 });
                            int dist[5][5][5] = { 0 };
                            dist[0][0][0] = 1;

                            while (!q.empty()) {
                                coordinate pos = q.front();
                                q.pop();

                                if (pos.x == 4 && pos.y == 4 && pos.z == 4)
                                    break;

                                for (int i = 0; i < 6; i++) {
                                    int nx = pos.x + dx[i];
                                    int ny = pos.y + dy[i];
                                    int nz = pos.z + dz[i];
                                    if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5)
                                        continue;
                                    if (dist[nz][nx][ny] != 0 || !cube[per[nz]][rotations[nz]][nx][ny])
                                        continue;
                                    dist[nz][nx][ny] = dist[pos.z][pos.x][pos.y] + 1;
                                    q.push({ nz, nx, ny });
                                }
                            }

                            if (dist[4][4][4] != 0 && dist[4][4][4] < mn)
                                mn = dist[4][4][4];
                        }
                    }
                }
            }
        }
    } while (next_permutation(per, 5));

    if (mn == 100000) {
        cout << -1;
    } else {
        cout << mn - 1;
    }

    return 0;
}