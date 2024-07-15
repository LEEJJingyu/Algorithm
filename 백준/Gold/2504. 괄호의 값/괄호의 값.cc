#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyStack {
private:
    vector<char> dat;
    int top = 0;

public:
    MyStack(int a) : dat(a) {}
    
    bool Empty() {
        return top == 0;
    }
    
    void Push(char a) {
        dat[top++] = a;
    }
    
    void Pop() {
        if (top != 0) top--;
    }
    
    char Top() {
        if (top != 0) return dat[top - 1];
        return '\0'; // 빈 스택일 때 적절한 값 반환
    }
    
    void Discard() {
        top = 0;
    }
};

int main() {
    string s;
    char status;
    int sum = 0;
    int num=1;
    bool error=false;
    MyStack d(30); // 최대 길이에 맞는 스택 크기 설정
    
    cin >> s;
    for (int i=0;i<s.size();i++) {
        if (s[i] == ')' && d.Top() == '(') {
            d.Pop();
            if(s[i-1]=='('){sum+=num;}num/=2;
        } else if (s[i] == ']' && d.Top() == '[') {
            d.Pop();
            if(s[i-1]=='['){sum+=num;}num/=3;
        } else if (s[i] == '[' ){
            num*=3;
        d.Push(s[i]);}
            else if (s[i] == '(') {
            num*=2;
        d.Push(s[i]);}
        else {
            error = true;
        }
    }

    if (!d.Empty()) error = true;
    if (error) sum = 0;
    
    cout << sum;
    return 0;
}