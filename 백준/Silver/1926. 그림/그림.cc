#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyQueue {
private:
    vector<pair<int,int>> dat;
    int head = 0;
    int rear = 0;

public:
    MyQueue(int a) : dat(a) {
        dat.resize(a); // 벡터의 크기를 설정
    }
    
    bool empty() {
        return head == rear;
    }
    
    void push(pair<int,int> a) {
        dat[rear++] = a;
    }
    
    void pop() {
        if (head!=rear) head++;
    }
    
    pair<int,int> front() {
        if (head != rear) return dat[head];
        return {0,0}; // 빈 큐일 때 적절한 값 반환
    }
};

int map[500][500];
int via[500][500] = {0,};

int main() {
    int n, m;
    MyQueue q(300000);
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int num = 0;
    int best = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(via[i][j] == 0 && map[i][j] == 1) {
                q.push({i, j});
                via[i][j] = 1; // 시작 노드를 방문 표시
                int temp = 1; // 새로운 그림의 넓이를 초기화

                while(!q.empty()) {
                    pair<int,int> pos = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = pos.first + dx[k];
                        int ny = pos.second + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(via[nx][ny] == 1 || map[nx][ny] == 0) continue;
                        via[nx][ny] = 1;
                        temp++;
                        q.push({nx, ny});
                    }
                }
                if(best < temp) best = temp;
                num++;
            }
        }
    }

    cout << num << '\n' << best;
    return 0;
}