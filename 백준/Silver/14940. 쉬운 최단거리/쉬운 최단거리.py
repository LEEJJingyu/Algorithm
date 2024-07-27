N, M = map(int,input().split())
dist = [ [ -1 for i in range(M) ] for j in range(N)]
board= []
queue = []
dir = [(0,1),(1,0),(-1,0),(0,-1)]
for i  in range(N) :
    s=list(map(int,input().split()))
    if 2 in s :
        dist[i][s.index(2)]=0
        queue.append((i,s.index(2)))
    board.append(s)
while queue != [] :
    x,y=queue[0]
    queue.remove((x,y))
    for i in dir :
        nx = x+i[0]
        ny = y+i[1]
        if nx < 0 or ny < 0 or nx >= N or ny >= M :
            continue
        if dist[nx][ny] >-1 :
            continue
        if not board[nx][ny] :
            dist[nx][ny]=0
            continue
        dist[nx][ny]=dist[x][y]+1 
        queue.append((nx,ny))
for idx1, i in enumerate(dist) :
    for idx2, j in enumerate(i) :
        if not board[idx1][idx2] :
            print(0,end=' ')
        else :
            print(j,end=' ')
    print()