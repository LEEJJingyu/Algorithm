#include<iostream>
#include<queue>
using namespace std;
int N, M, K;
int window[40][40];
int sticker[100][10][10];
pair<int, int> coordinate[100];
void rotate_90(int k)
{
	int c = coordinate[k].second;
	int r = coordinate[k].first;
        
	int** stick = new int*[c];
	for (int i = 0; i < c; i++)
		stick[i] = new int[r];
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			stick[i][j] = sticker[k][r-j-1][i];
	for (int i = 0; i < c; i++){
		for (int j = 0; j < r; j++){
			sticker[k][i][j]=stick[i][j];
        }
    }
	coordinate[k] = { c,r };
}
int attach()
{
	for (int i = 0; i < K; i++)
	{
        
		int rotate = 0;
		bool isused = false;
		while (!isused) {
			if (rotate == 360)break;
			int c = coordinate[i].first;
			int r = coordinate[i].second;
			bool isuse = true;
			for (int j = 0; j < N - c + 1; j++)
				for (int k = 0; k < M - r + 1; k++) {
					isuse = true;
					for (int x = 0; x < c; x++){
						for (int y = 0; y <r; y++){
							if (sticker[i][x][y]==1&&window[x+j][y+k]==1)
									isuse = false;
                        }
                    }
					if (isuse)
					{
						for (int x = 0; x < c; x++)
                            for (int y = 0; y <r; y++)
                                if (sticker[i][x][y]==1)
									window[x+j][y+k] = 1;/*
						for (int x = 0; x < c; x++) {
							for (int y = 0; y < r; y++) {
								cout << sticker[i][x][y] << ' ';
							}
							cout << '\n';
						}
						cout << '\n';*/
						j = N;
						k = N;
						isused = true;
					}
				}
			if (!isused)
			{
				rotate += 90;
				rotate_90(i);
			}
		}

	}
	int sm = 0;
	for (int  i= 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			sm += window[i][j];
		}
    }
    
	return sm;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> c >> r;
		coordinate[i] = { c,r };
		for (int x = 0; x < c; x++)
			for (int y = 0; y < r; y++)
				cin >> sticker[i][x][y];
	}
	cout << attach();
}