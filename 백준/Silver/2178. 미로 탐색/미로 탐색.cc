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
    MyQueue(int a) : dat(a) {}
    
    bool empty() {
        return head == rear;
    }
    
    void push(pair<int,int> a) {
        dat[rear++] = a;
    }
    
    void pop() {
        if (head != rear) head++;
    }
    
    pair<int,int> front() {
        if (head != rear) return dat[head];
        return {0,0}; // 빈 큐일 때 적절한 값 반환
    }
};

	int via[101][101]={-1,};

int main() {
    int n, m;
    string map[101];
    MyQueue q(300000);
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    cin >> n >> m;

    // 지도 입력
    for(int i = 0; i < n; i++) {
        cin >> map[i];
        fill(via[i],via[i]+m,-1);
    }

    via[0][0] = 1; // 시작 위치를 1로 설정
    q.push({0, 0});
    
    while(!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = pos.first + dx[k];
            int ny = pos.second + dy[k];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(via[nx][ny] != -1 || map[nx][ny]!= '1') continue;
            via[nx][ny] = via[pos.first][pos.second] + 1;
            q.push({nx, ny});
        }
    }
    
    cout << via[n-1][m-1];
    
    return 0;
}