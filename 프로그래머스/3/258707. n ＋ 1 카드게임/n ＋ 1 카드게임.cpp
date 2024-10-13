#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int check[1001];
int solution(int coin, vector<int> cards) {
    int answer = 0;
    int cnt=0;
    unordered_set<int> bag;
    memset(check,0,sizeof check);
    int n = cards.size();
    for(int i=0;i<n/3;i++)
    {
        check[cards[i]]=true;
        if(check[n+1-cards[i]])
        {
            cnt++;
        }
    }
    while(coin>=0)
    {
        if(n/3+answer*2==n){
            answer++;
            break;
        }
        bag.insert(cards[n/3+answer*2]);
        bag.insert(cards[n/3+answer*2+1]);
        answer++;
        if(cnt)
            cnt--;
        else{
            bool flag = true;
            for(int i : bag)
            {
                if(check[n+1-i]){
                    bag.erase(i);
                    coin--;
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(coin<=1)
                    return answer;
                for(int i : bag)
                {
                    if(bag.find(n+1-i)!=bag.end()){
                        bag.erase(i);
                        bag.erase(n+1-1);
                        coin-=2;
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return answer;
                }
            }
        }
    }
    return answer;
}