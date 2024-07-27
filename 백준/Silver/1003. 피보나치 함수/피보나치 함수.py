T =int(input())
case = [ int(input()) for i in range(T) ]
mem = [(-1,-1) for i in range(41)]
mem[0]=(1,0)
mem[1]=(0,1)
def func(k) :
    if mem[k] != (-1,-1) :
        return mem[k]
    a = func(k-1)
    b = func(k-2)
    mem[k] = (a[0]+b[0],a[1]+b[1])
    return mem[k]

for i in case :
    print(*func(i))
    