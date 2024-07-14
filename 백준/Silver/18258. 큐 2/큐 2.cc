#include<iostream>
#include<string>
using namespace std;
struct Queue_s{
    int dat[2000000];
    int head=0;
    int rear=0;
    int push(int x)
    {
        dat[rear++]=x;
        return x;
    }
    int pop()
    {
        if(rear-head!=0){return dat[head++];}
        else return -1;
    }
    int size()
    {
       return rear-head; 
    }
    int empty()
    {
        if(rear==head)return 1;
        else return 0;
    }
    int front()
    {
        if(head!=rear)return dat[head];
        else return -1;
    }
    int back()
    {
        if(head!=rear)return dat[rear-1];
        else return -1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string com;
    int T;
    int n;
    Queue_s q;
    cin >> T;
    while(T--)
    {
        cin >> com;
        if(com=="push"){cin >> n;q.push(n);}
        else if(com=="pop"){cout << q.pop()<<'\n';}
        else if(com=="size"){cout << q.size()<<'\n';}
        else if(com=="empty"){cout << q.empty()<<'\n';}
        else if(com=="front"){cout << q.front()<<'\n';}
        else if(com=="back"){cout << q.back()<<'\n';}
    }
}