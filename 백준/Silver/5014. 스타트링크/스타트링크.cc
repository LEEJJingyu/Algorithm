#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int F, S, G, U, D;
    cin >> F >> S>>G>>U>>D;
    vector<int> map(F+1,-1);
    queue<pair<int,int>> q;
    map[S]=0;
    q.push({S,0});
    bool possible=true;
    while(!q.empty()&&possible)
    {
        pair<int,int> cur = q.front();
        q.pop();
        int dx[2]={cur.first+U,cur.first-D};
        for(int i=0;i<2;i++)
        {
            if(dx[i]<1||dx[i]>F)continue;
            if(map[dx[i]]!=-1)continue;
            map[dx[i]]=cur.second+1;
            q.push({dx[i],map[dx[i]]});
        }
        if(cur.first==G){cout << cur.second; break;}
        if(q.empty())cout<<"use the stairs";
    }
}