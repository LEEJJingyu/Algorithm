a = int(input())
c = 0
if a//5> 3 :
    c=a//5-3
    a-=c*5
def func(N,K) :
    if N == a :
        return K
    elif N > a :
        return -1
    b = func(N+5,K+1)
    if b==-1 :
        return func(N+3,K+1)
    else :
    	return b
print(func(0,c))