#include <iostream>
using namespace std;

int N;
int map[20][20];
int mx = 0;

void moving(int dir) {
    int temp[20][20] = {0};
    
    switch (dir) {
        case 1: // Left
            for (int i = 0; i < N; i++) {
                int st = 0;
                for (int j = 0; j < N; j++) {
                    if (map[i][j] != 0) {
                        if (temp[i][st] == 0) {
                            temp[i][st] = map[i][j];
                        } else if (temp[i][st] == map[i][j]) {
                            temp[i][st] *= 2;
                            st++;
                        } else {
                            st++;
                            temp[i][st] = map[i][j];
                        }
                    }
                }
            }
            break;
        case 2: // Up
            for (int j = 0; j < N; j++) {
                int st = 0;
                for (int i = 0; i < N; i++) {
                    if (map[i][j] != 0) {
                        if (temp[st][j] == 0) {
                            temp[st][j] = map[i][j];
                        } else if (temp[st][j] == map[i][j]) {
                            temp[st][j] *= 2;
                            st++;
                        } else {
                            st++;
                            temp[st][j] = map[i][j];
                        }
                    }
                }
            }
            break;
        case 3: // Right
            for (int i = 0; i < N; i++) {
                int st = N - 1;
                for (int j = N - 1; j >= 0; j--) {
                    if (map[i][j] != 0) {
                        if (temp[i][st] == 0) {
                            temp[i][st] = map[i][j];
                        } else if (temp[i][st] == map[i][j]) {
                            temp[i][st] *= 2;
                            st--;
                        } else {
                            st--;
                            temp[i][st] = map[i][j];
                        }
                    }
                }
            }
            break;
        case 4: // Down
            for (int j = 0; j < N; j++) {
                int st = N - 1;
                for (int i = N - 1; i >= 0; i--) {
                    if (map[i][j] != 0) {
                        if (temp[st][j] == 0) {
                            temp[st][j] = map[i][j];
                        } else if (temp[st][j] == map[i][j]) {
                            temp[st][j] *= 2;
                            st--;
                        } else {
                            st--;
                            temp[st][j] = map[i][j];
                        }
                    }
                }
            }
            break;
    }
    
    // Copy temp back to map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

void search(int k) {
    if (k == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mx < map[i][j]) {
                    mx = map[i][j];
                }
            }
        }
        return;
    }
    
    int temp[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = map[i][j];
        }
    }
    
    moving(1);
    search(k + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[i][j];
        }
    }
    
    moving(2);
    search(k + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[i][j];
        }
    }
    
    moving(3);
    search(k + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[i][j];
        }
    }
    
    moving(4);
    search(k + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    search(0);
    cout << mx;
}