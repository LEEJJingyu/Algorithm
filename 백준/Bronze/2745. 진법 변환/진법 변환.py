N, B = map(str, input().split())
B = int(B)
N = ''.join(reversed(N))
number = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
total_sum = 0

for x in range(len(N) - 1, -1, -1):
    total_sum += number.index(N[x]) * B ** x

print(total_sum)
