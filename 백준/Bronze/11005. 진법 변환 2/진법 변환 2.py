N, B = map(int, input().split())

numbers = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'


p = []
while N >= B:

     p.append(N % B)
     N = (N // B)



p.append(N)
num = p[::-1]
for i in num:
    number=numbers[i]
    
    print(number,end = '')