#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

bool isnotprime[3001];
void init(){
    for(int i=2;i*i<=3000;i++){
        if(isnotprime[i])continue;
        for(int j=i*i;j<=3000;j+=i){
            isnotprime[j]=true;
        }
    }
    
}
int answer=0;
void select(int depth,int sum, vector<int>& nums, int st)
{
    if(depth==3)
    {
        if(!isnotprime[sum])
            answer++;
        return;
    }
    for(int i = st;i<nums.size();i++){
        select(depth+1,sum+nums[i],nums,i+1);
    }
}

int solution(vector<int> nums) {
    answer = 0;
    memset(isnotprime,0,sizeof isnotprime);
    init();
    select(0,0,nums,0);
    return answer;
}