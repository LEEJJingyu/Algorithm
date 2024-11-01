#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
int N,M, depth[40001];
int parent[40001][17];
int dist[40001][17];
vector<pair<int,int>> adj[40001];
void FindParent(int par, int now, int dep, int cost){
  depth[now] = dep;
  parent[now][0] = par;
  dist[now][0] = cost;
  for(auto nxt : adj[now]){
    if(nxt.second != par)
      FindParent(now, nxt.second, dep+1,nxt.first);
  }
}
int func(int a, int b){
  int sum=0;
if(depth[a] < depth[b]) //깊이가 다르다면 a가 항상 더 깊게
  swap(a,b);

int dif = depth[a] - depth[b];
for(int i=0; dif>0 ; ++i){
  if(dif %2 ==1){
    sum += dist[a][i];
    a = parent[a][i];
  }
  dif = dif>>1;
}

  if(a != b){
    for(int k = 16; k>=0 ; --k){
      if(parent[a][k] != 0 && parent[a][k] != parent[b][k]){
        sum+= (dist[a][k] + dist[b][k]);
        a = parent[a][k];
        b = parent[b][k];
      }
    }

    sum += dist[a][0] + dist[b][0];
  }
  
  return sum;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;i++){
        int u,v,cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u});
    }
    FindParent(0,1,0,0);
    for(int k=1; k<17 ; ++k){
    for(int idx = 2 ; idx<=N ; ++idx){
      if(parent[idx][k-1] != 0){
        parent[idx][k] = parent[parent[idx][k-1]][k-1];
        dist[idx][k] = dist[idx][k-1] + dist[parent[idx][k-1]][k-1];
      }
    }
  }
    cin >> M;
    while(M--){
        int a, b;
        cin >> a >> b;
        cout<<func(a,b)<<'\n';
    }
    return 0;
}