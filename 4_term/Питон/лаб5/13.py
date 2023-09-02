string = input().split()

print(any(not all(map(int, x.split())) for x in string if x == '0'))
