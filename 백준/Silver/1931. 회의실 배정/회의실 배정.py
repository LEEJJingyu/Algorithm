T = int(input())
meetings = [list(map(int, input().split())) for _ in range(T)]
meetings.sort(key=lambda x: (x[1], x[0]))
def max_meetings(meetings):
    count = 0
    end_time = 0
    for start, end in meetings:
        if start >= end_time:
            count += 1
            end_time = end
    return count

print(max_meetings(meetings))