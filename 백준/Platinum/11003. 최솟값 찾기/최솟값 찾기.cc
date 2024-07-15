#include <iostream>
#include <vector>
using namespace std;

class MyDeque {
private:
    vector<pair<int, int>> dat;
    int capacity;
    int head, rear;
public:
    MyDeque(int cap) : capacity(cap), dat(cap), head(0), rear(0) {}

    void push_front(pair<int, int> x) {
        head = (head - 1 + capacity) % capacity;
        dat[head] = x;
    }

    void push_back(pair<int, int> x) {
        dat[rear] = x;
        rear = (rear + 1) % capacity;
    }

    void pop_front() {
        head = (head + 1) % capacity;
    }

    void pop_back() {
        rear = (rear - 1 + capacity) % capacity;
    }

    bool empty() {
        return head == rear;
    }

    int size() {
        return (rear - head + capacity) % capacity;
    }

    pair<int, int> front() {
        return dat[head];
    }

    pair<int, int> back() {
        return dat[(rear - 1 + capacity) % capacity];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    MyDeque q(N + 1); // 원형 버퍼 크기는 N + 1로 설정

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        while (!q.empty() && q.back().second >= n)
            q.pop_back();

        q.push_back({ i, n });

        while (q.front().first <= i - L)
            q.pop_front();

        cout << q.front().second << ' ';
    }

    return 0;
}