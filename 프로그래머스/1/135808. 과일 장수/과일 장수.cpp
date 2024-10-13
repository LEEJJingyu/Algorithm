#include <string>
#include <cstring>
#include <vector>

using namespace std;
int cnt[10];
int solution(int k, int m, vector<int> score) {
    memset(cnt,0,sizeof cnt);
    for(int i : score)
        cnt[i]++;
    int answer = 0;
    int prev=0;
    for(int i=k;i>0;i--){
        while(cnt[i]){
            if(cnt[i]+prev>=m)
            {
                answer+=m*i;
                cnt[i]-=(m-prev);
                prev=0;
            }
            else{
                prev+=cnt[i];
                cnt[i]=0;
            }
        }
    }
    return answer;
}