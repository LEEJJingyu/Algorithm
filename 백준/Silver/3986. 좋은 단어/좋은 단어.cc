#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyStack
{
private:
    vector<char> dat;
    int top = 0;

public:
    MyStack(int a) : dat(a) {}

    bool Empty()
    {
        return top == 0;
    }

    void Push(char a)
    {
        dat[top++] = a;
    }

    void Pop()
    {
        if (top != 0)
            top--;
    }

    char Top()
    {
        if (top != 0)
            return dat[top - 1];
        return '\0'; // 빈 스택일 때 적절한 값 반환
    }

    int Size()
    {
        return top;
    }

    void Discard()
    {
        top = 0;
    }
};

int main()
{
    string s;
    int T;
    int num = 0; // num 초기화
    MyStack d(1000000);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        for (char c : s)
        {
            if (c == 'A' && d.Top() == 'A')
                d.Pop();
            else if (c == 'B' && d.Top() == 'B')
                d.Pop();
            else
                d.Push(c);
        }
        if (d.Empty())
            num++;
        d.Discard(); // 스택 비우기
    }
    cout << num;
    return 0;
}