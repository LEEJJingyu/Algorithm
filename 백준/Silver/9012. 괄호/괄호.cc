#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MyStack
{
    private :
        vector<char> dat;
        int top=0;
    public :
        MyStack(int a) : dat(a) {}
        bool Empty()
        {
            return top==0;
        }
        void Push(char a)
        {
            dat[top++]=a;        
        }
        void Pop()
        {
            if(top!=0)top--;
        }
        char Top()
        {
            if(top!=0)return dat[top-1];
        }
        int Size()
        {
            return top;
        }
    	void Discard()
        {
            top=0;
        }
};

int main()
{
    string s;
    int T;
    MyStack d(100000);
    cin >> T;
    bool nooo;
    for(int i=0;i<T;i++)
    {
        nooo = false;
        cin>>s;
        for(char c : s)
        {
            if(c==')'&&d.Top()=='(')d.Pop();
            else if(c=='(')d.Push(c);
            else { nooo=true; break;}
        }
        if(!d.Empty())nooo=true;
        if(nooo)cout << "NO\n";
        else cout << "YES\n";
        d.Discard();
    	
    }
}