#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
bool timer[101][101][20001];
bool visited[101][101][20001];



int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    memset(timer,0,sizeof timer);
    memset(visited,0,sizeof visited);
    for(vector<int> route : routes)
    {
        int t=0;
        int x = points[route[0]-1][0], y = points[route[0]-1][1];
        
        if(!timer[x][y][t]){
        timer[x][y][t]=true;
        }
        else if(!visited[x][y][t]){
            visited[x][y][t]=true;
            answer++;
        }
        for(int i=1;i<route.size();i++){
            while(x!=points[route[i]-1][0])
            {
                t++;
                if(x<points[route[i]-1][0])
                    x++;
                else
                    x--;
                if(!timer[x][y][t]){
                    timer[x][y][t]=true;
                }
                else if(!visited[x][y][t]){
                    visited[x][y][t]=true;
                    answer++;
                }
            }
            while(y!=points[route[i]-1][1])
            {
                t++;
                if(y<points[route[i]-1][1])
                    y++;
                else
                    y--;
                if(!timer[x][y][t]){
                    timer[x][y][t]=true;
                }
                else if(!visited[x][y][t]){
                    visited[x][y][t]=true;
                    answer++;
                }
            }
        }
    }
    return answer;
}