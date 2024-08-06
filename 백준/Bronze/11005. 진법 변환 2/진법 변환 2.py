def power(N,B):
    if N < B:
        return p.append(N)
    p.append(N % B)
    N = N // B
    return  power(N,B)





N, B = map(int, input().split())

numbers = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

p = []
# while N > B:
#
#      p.append(N % B)
#      N = (N // B)
#
#
#
# p.append(N)
power(N,B)

num = p[::-1]
for i in num:
    number=numbers[i]

    print(number,end = '')