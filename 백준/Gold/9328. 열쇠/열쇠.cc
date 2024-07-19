#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
bool keys[26];
char map[101][101];
bool dist[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int test_case = 1; test_case<=T;test_case++)
    {
		vector<queue<pair<int,int>>> door(26);
        int h,w;
		int result=0;
        string key;
        cin >> h>>w;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
                cin>>map[i][j];
            fill(dist[i],dist[i]+w,false);
        }
        for(int i=0;i<26;i++)
            fill(keys,keys+26,0);
        cin >> key;
        if(key!="0")for(int i=0;i<key.size();i++)keys[key[i]-'a']=true;
        queue<pair<int,int>> q;
        for(int i=0;i<w;i++)
        {
            if(map[0][i]=='.'||map[0][i]=='$')
            {
                if(map[0][i]=='$')result++;
                dist[0][i]=true;
                q.push({0,i});
            }
            else if(map[0][i]>='A'&&map[0][i]<='Z')
            {
                dist[0][i]=true;
                door[map[0][i]-'A'].push({0,i});
            }
            else if(map[0][i]>='a'&&map[0][i]<='z')
            {
                dist[0][i]=true;
                q.push({0,i});
                keys[map[0][i]-'a']=true;
            }
            if(map[h-1][i]=='.'||map[h-1][i]=='$')
            {
                if(map[h-1][i]=='$')result++;
                dist[h-1][i]=true;
                q.push({h-1,i});
            }
            else if(map[h-1][i]>='A'&&map[h-1][i]<='Z')
            {
                dist[h-1][i]=true;
                door[map[h-1][i]-'A'].push({h-1,i});
            }
            else if(map[h-1][i]>='a'&&map[h-1][i]<='z')
            {
                dist[h-1][i]=true;
                q.push({h-1,i});
                keys[map[h-1][i]-'a']=true;
            }
        }
        for(int i=1;i<h-1;i++)
        {
            if(map[i][0]=='.'||map[i][0]=='$')
            {
                if(map[i][0]=='$')result++;
                dist[i][0]=true;
                q.push({i,0});
            }
            else if(map[i][0]>='A'&&map[i][0]<='Z')
            {
                dist[i][0]=true;
                door[map[i][0]-'A'].push({i,0});
            }
            else if(map[i][0]>='a'&&map[i][0]<='z')
            {
                dist[i][0]=true;
                q.push({i,0});
                keys[map[i][0]-'a']=true;
            }
            if(map[i][w-1]=='.'||map[i][w-1]=='$')
            {
                if(map[i][w-1]=='$')result++;
                dist[i][w-1]=true;
                q.push({i,w-1});
            }
            else if(map[i][w-1]>='A'&&map[i][w-1]<='Z')
            {
                dist[i][w-1]=true;
                door[map[i][w-1]-'A'].push({i,w-1});
            }
            else if(map[i][w-1]>='a'&&map[i][w-1]<='z')
            {
                dist[i][w-1]=true;
                q.push({i,w-1});
                keys[map[i][w-1]-'a']=true;
            }
        }
        if(q.empty())
            {
                for(int i=0;i<26;i++)
                {
                    if(keys[i]){
                        while(!door[i].empty())
                        {
                            q.push(door[i].front());
                            door[i].pop();
                        }
                    }
                }
            }
        while(!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=cur.first+dx[i];
                int ny=cur.second+dy[i];
                if(nx<0||ny<0||nx>=h||ny>=w)continue;
                if(map[nx][ny]=='*'||dist[nx][ny])continue;
                if(map[nx][ny]=='$'){result++;}
                else if(map[nx][ny]>='a'&&map[nx][ny]<='z')
                {
                	keys[map[nx][ny]-'a']=true;
                }
                else if(map[nx][ny]>='A'&&map[nx][ny]<='Z'){
                    door[map[nx][ny]-'A'].push({nx,ny});
                    dist[nx][ny]=true;
                    continue;
                }
                q.push({nx,ny});
                dist[nx][ny]=true;
            }
            if(q.empty())
            {
                for(int i=0;i<26;i++)
                {
                    if(keys[i]){
                        while(!door[i].empty())
                        {
                            q.push(door[i].front());
                            door[i].pop();
                        }
                    }
                }
            }
        }
        cout<<result<<'\n';
    }
    
}