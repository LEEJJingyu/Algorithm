#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

pair<int, int> num[252];
int val[2][601];
int n, mxN[5] = { 2, 6, 20, 70, 252 };

void combinationUtil(const vector<int>& arr, vector<int>& com, int start, int end, int index, int r, vector<vector<int>>& result) {
    if (index == r) {
        result.push_back(com);  // 현재 조합을 저장
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        com[index] = arr[i];
        combinationUtil(arr, com, i + 1, end, index + 1, r, result);
    }
}

vector<vector<int>> combination(const vector<int>& arr, int r) {
    vector<vector<int>> result;
    vector<int> com(r);
    combinationUtil(arr, com, 0, arr.size() - 1, 0, r, result);
    return result;
}

void roll(int depth, int sum, int status, const vector<vector<int>>& dice, const vector<int>& order) {
    if (depth == n) {
        val[status][sum]++;
        return;
    }
    for (int nxt : dice[order[depth]]) {
        roll(depth + 1, sum + nxt, status, dice, order);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    memset(num, 0, sizeof num);
    n = dice.size() / 2;
    vector<int> arr(n * 2);
    for (int i = 0; i < n * 2; i++)
        arr[i] = i;

    vector<vector<int>> com = combination(arr, n);  // n개의 조합을 구함

    for (int i = 0; i < mxN[n - 1]; i++) {
        memset(val, 0, sizeof val);

        // 선택된 n개의 조합을 통해 첫 번째 roll
        roll(0, 0, 0, dice, com[i]);

        // 선택되지 않은 나머지 원소들 계산
        vector<int> remaining;
        for (int j = 0; j < n * 2; j++) {
            if (find(com[i].begin(), com[i].end(), j) == com[i].end()) {
                remaining.push_back(j);
            }
        }

        // 나머지 원소들로 두 번째 roll
        roll(0, 0, 1, dice, remaining);

        // prefix sum 계산
        for (int j = 1; j < 601; j++) {
            val[1][j] += val[1][j - 1];
        }

        // 승리, 무승부 수 계산
        for (int j = 1; j < 601; j++) {
            if (val[0][j] == 0) continue;
            num[i].first += val[1][j - 1] * val[0][j];
            num[i].second += (val[1][j] - val[1][j - 1]) * val[0][j];
        }
    }

    // 최대 승리, 무승부 찾기
    int mxIdx = 0;
    int mxWin = -1;
    int mxDraw = 0;
    for (int i = 0; i < mxN[n - 1]; i++) {
        if (mxWin < num[i].first) {
            mxIdx = i;
            mxWin = num[i].first;
            mxDraw = num[i].second;
        }
        else if (mxWin == num[i].first && mxDraw == num[i].second) {
            mxDraw = num[i].second;
            mxIdx = i;
        }
    }
    for (int& i : com[mxIdx])
        i++;
    return com[mxIdx];
}

