#include <string>
#include <vector>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;
bool visited[1000001];
pair<int,int> status[1000001];
vector<int> nxt[1000001];
int search(int st)//0 donut ,1 stick,2 (8)
{
    stack<int> s;
    s.push(st);
    while(!s.empty())
    {
        int cur = s.top(); s.pop();
        if(visited[cur]){
            return 1;
        }
        visited[cur]=true;
        if(status[cur].first>1)
            return 3;
        for(int i : nxt[cur])
        {
            s.push(i);
        }
    }
    return 2;
}


vector<int> solution(vector<vector<int>> edges) {
    memset(visited, 0 ,sizeof visited);
    memset(nxt, 0 ,sizeof nxt);
    memset(status, 0 ,sizeof status);
    vector<int> answer(4);
    
    for(vector<int> edge : edges)
    {
        nxt[edge[0]].push_back(edge[1]);
        status[edge[0]].first++;
        status[edge[1]].second++;
    }
    for(int i=0;i<1000000;i++)
    {
        if(status[i].first>1&&status[i].second==0){
            answer[0]=i;
            break;
        }
    }
    for(int cur : nxt[answer[0]])
    {
        status[cur].second--;
        answer[search(cur)]++;
    }
    
    return answer;
}