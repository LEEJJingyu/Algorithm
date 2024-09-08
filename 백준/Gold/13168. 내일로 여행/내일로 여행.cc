#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<tuple>
using namespace std;

int N,R,M,K;
unordered_map<string, int> city;
vector<pair<int, string>> arr[100][100];
int noNaeil[100][100];
int goNaeil[100][100];
vector<int> route;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        city[s] = i;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        route.push_back(city[s]);
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        string trans, u, v;
        int cost;
        cin >> trans >> u >> v >> cost;
        int uN = city[u], vN = city[v];
        arr[uN][vN].push_back({cost*2,trans});
        arr[vN][uN].push_back({ cost*2,trans });
    }
    for (int i = 0; i < N; i++)
    {
        fill(noNaeil[i], noNaeil[i] + N, 1e9);
        fill(goNaeil[i], goNaeil[i] + N, 1e9);
        noNaeil[i][i] = 0;
        goNaeil[i][i] = 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)continue;
            for (auto imp : arr[i][j])
            {
                noNaeil[i][j] = min(noNaeil[i][j], imp.first);
                if (imp.second == "ITX-Cheongchun" || imp.second == "ITX-Saemaeul" || imp.second == "Mugunghwa")
                    goNaeil[i][j] = 0;
                else if (imp.second == "S-Train" || imp.second == "V-Train")
                    goNaeil[i][j] = min(goNaeil[i][j], imp.first / 2);
                else
                    goNaeil[i][j] = min(goNaeil[i][j], imp.first);
            }
        }
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                noNaeil[i][j] = min(noNaeil[i][j], noNaeil[i][k] + noNaeil[k][j]);
                goNaeil[i][j] = min(goNaeil[i][j], goNaeil[i][k] + goNaeil[k][j]);
            }
    int sumN = 0, sumG = R*2;
    for (int i=1;i<route.size();i++)
    {
        sumN += noNaeil[route[i - 1]][route[i]];
        sumG += goNaeil[route[i - 1]][route[i]];
    }
    if (sumN > sumG)
        cout << "Yes";
    else
        cout << "No";
}