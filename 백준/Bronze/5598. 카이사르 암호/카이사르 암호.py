# https://www.acmicpc.net/problem/5598

alp = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N','O', 'P', 'Q', 'R', 'S', 'T','U','V', 'W', 'X', 'Y', 'Z']
key_num = 3
alp.extend(alp[:key_num])
key = { alp[i+key_num] : alp[i] for i in range(len(alp)-key_num)}

N = input().strip()
def change(arr) :
    return ''.join([key[i] for i in arr ])

print(change(N))
