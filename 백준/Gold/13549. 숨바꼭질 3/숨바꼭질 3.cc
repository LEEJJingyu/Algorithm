#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int N,K;
    cin>>N>>K;
    int max;
    if(N<=K)max=(K*3)/2+2;
    else max=N+1;
    vector<int> x(max,max);
    queue<int> q;
    x[N]=0;
    q.push(N);
    int T=max;
    while(T--)
    {
        int cur = q.front();
        q.pop();
        int ch[3]={cur-1,cur+1,cur*2};
        for(int i=0;i<3;i++)
        {
            if(ch[i]<0||ch[i]>=max)continue;
            if(x[ch[i]]<=x[cur])continue;
            q.push(ch[i]);
            if(i==2){x[ch[i]]=x[cur];}
            else x[ch[i]]=x[cur]+1;
        }
    }
    cout<<x[K];
}