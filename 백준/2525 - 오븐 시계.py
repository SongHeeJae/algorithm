hour, min = map(int, input().split(" "))
time = int(input())
min = min + time
hour = (hour + min // 60) % 24
print(hour, min % 60)