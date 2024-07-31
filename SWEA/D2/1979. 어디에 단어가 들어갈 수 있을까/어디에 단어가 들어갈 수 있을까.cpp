T = int(input())
for tc in range(T) :
    N ,K = map(int,input().split())
    word = [ list(map(int,input().split())) for _ in range(N)]
    cnt=0
    for i in range(N) :
        row = col =0
        isWord_R=isWord_C = False
        for j in range(N) :
            if word[i][j] :
                row+=1
                isWord_R = True
            elif isWord_R :
                if row == K :
                    cnt+=1
                    isWord_R = False
                row =0
            if word[j][i] :
                col+=1
                isWord_C = True
            elif isWord_C :
                if col == K :
                    cnt+=1
                    isWord_C = False
                col=0
        if isWord_C and col == K :
            cnt+=1
        if isWord_R and row == K :
            cnt+=1
    print(f'#{tc+1} {cnt}')
                
            