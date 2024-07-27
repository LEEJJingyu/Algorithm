N, M = map(int,input().split())
cable = [ int(input()) for i in range(N)]
def count_cables(length):
    count = 0
    for cable_length in cable:
        count += cable_length // length
    return count

def binary_search():
    left, right = 1, max(cable)
    result = 0

    while left <= right:
        mid = (left + right) // 2
        if count_cables(mid) >= M:
            result = mid
            left = mid + 1
        else:
            right = mid - 1

    return result

print(binary_search())
