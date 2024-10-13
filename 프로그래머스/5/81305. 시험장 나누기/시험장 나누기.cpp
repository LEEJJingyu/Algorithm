#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
vector<int> adj[10001];
int n, m;
bool vis[10001];
int cnt[10001];
int remain=0;
int func(int node, vector<int>& num,int md){
    if(remain>m)return 0;
    priority_queue<int> pq;
    int sum = 0;
    vis[node] = true;
    for(int nxt : adj[node]){
        if(!vis[nxt]){
            int sum_subtree = func(nxt,num,md);
            sum += sum_subtree;
            pq.push(sum_subtree);   
        }
    }
    while(!pq.empty() && sum + num[node] > md){
        remain++;
        sum -= pq.top(); pq.pop();   
    }
    return sum + num[node];
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    n=num.size();
    m=k;
    int st=0,ed=0;
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++)
    {
        st=max(st,num[i]);
        ed+=num[i];
        for(int j=0;j<2;j++){
            if(links[i][j]!=-1){
                adj[i].push_back(links[i][j]);
                cnt[links[i][j]]++;
            }
        }
    }
    int root = 0;
    for(int i = 0;i<n;i++){
        if(cnt[i]==0){
            root = i;
            break;
        }
    }
    
    while(st<ed){
        memset(vis,0,sizeof vis);
        remain=1;
        int md = (st+ed)>>1;
        func(root,num,md);
        if(remain<=k)
            ed=md;
        else
            st=md+1;
    }
    
    
    return ed;
}