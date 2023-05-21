import math

numbers = input().split()

print(*sorted(numbers, key=lambda x: abs(int(x)), reverse=True))
# 3 6 -8 2 -78 1 23 -45 9
