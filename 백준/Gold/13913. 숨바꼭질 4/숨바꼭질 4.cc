#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> sett(max,0);
    queue<int> q;
    x[N]=0;
    q.push(N);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        int ch[3]={cur-1,cur+1,cur*2};
        for(int i=0;i<3;i++)
        {
            if(ch[i]<0||ch[i]>=max)continue;
            if(x[ch[i]]<=x[cur])continue;
            q.push(ch[i]);
            sett[ch[i]]=cur;
            x[ch[i]]=x[cur]+1;
        }
    }
    cout<<x[K]<<'\n';
    int temp=K;
    vector<int> tt;
    while(temp!=N)
    {
        tt.push_back(temp);
        temp=sett[temp];
    }
    tt.push_back(temp);
    for(int i=tt.size()-1;i>=0;i--)
    {
        cout<<tt[i]<<' ';
    }
    
}