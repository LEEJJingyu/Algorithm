#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
string s;
int t = 0;
int pos =4 ;
stack<int> num;
bool isplus = false;
int mns = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            t += (c - '0') * pow(10, pos);
            pos--;
        }
        else
        {
            t /= pow(10, pos+1);
            pos = 4;
            if (isplus)
            {
                t += num.top();
                num.pop();
                isplus = false;
            }
            if (c == '-')
            {
                num.push(t);
                mns++;
                t = 0;
            }
            else if (c == '+')
            {
                num.push(t);
                isplus = true;
                t = 0;
            }
        }
    }
    t /= pow(10, pos+1);
    if (isplus)
    {
        t += num.top();
        num.pop();
        isplus = false;
    }
    num.push(t);
    while (mns>1)
    {
        mns--;
        int a, b;
        a = num.top(); num.pop();
        b = num.top(); num.pop();
        num.push(a + b);
    }
    if (mns)
    {
        int a, b;
        a = num.top(); num.pop();
        b = num.top(); num.pop();
        cout << b-a;
    }
    else
    {
        cout<<num.top();
    }

}
