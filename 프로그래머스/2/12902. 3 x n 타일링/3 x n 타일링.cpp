#include <string>
#include <cstring>
#include <vector>

using namespace std;
long long arr[2501][2]={0};
int solution(int n) {
    if(n%2)
        return 0;
    if(arr[n/2-1][0])
        return arr[n/2-1][0];
    arr[0][0]=3;
    arr[0][1]=1;
    for(int i=1;i<n/2;i++)
    {
        if(arr[i][0])continue;
        arr[i][0]=(arr[i-1][0]*3)+(arr[i-1][1]*2);
        arr[i][1]=arr[i-1][1]+arr[i-1][0];
        arr[i][0]%=1000000007;
        arr[i][1]%=1000000007;
    }
    int answer = arr[n/2-1][0];
    return answer;
}