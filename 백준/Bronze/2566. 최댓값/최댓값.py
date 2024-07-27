a = [ list(map(int,input().split())) for i in range(9) ]
mx=a[0][0]
x,y=1,1
for idx1, i in enumerate(a) :
    for idx2, j in enumerate(i) :
        if mx < j :
            mx = j
            x,y=idx1+1,idx2+1
            
print(f'{mx}\n{x} {y}')