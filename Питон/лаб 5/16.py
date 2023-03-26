import math
import functools

result = map(int, input().split())
print(functools.reduce(math.gcd, result))
