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
    bool whaterror;
    MyStack d(100);
    whaterror=false;
    while(true)
    {
    	getline(cin,s);
        if(s==".")break;
        for(char c : s)
        {
            if(c=='['||c=='('){
                d.Push(c);
            }
            else if(c==']'||c==')')
            {
                if(c==']'&&d.Top()=='[')d.Pop();
                else if(c==')'&&d.Top()=='(')d.Pop();
                else {whaterror = true;}
            }
            else if(c=='.'){
                if(!d.Empty())whaterror=true;
            	if(whaterror)cout<< "no\n";
            	else cout << "yes\n";
    			whaterror = false;
                d.Discard();
            }
        }
    	
    }
}