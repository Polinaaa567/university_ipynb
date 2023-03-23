print(*filter(lambda x: x < 5, range(10)))

print(*map(lambda x: x/2, range(15)))

print(*map(lambda x: x/2, filter(lambda x: x / 2 > 17, range(50))))

print(sum(map(lambda x: x ** 2, filter(lambda x: not x % 9, range(10, 100)))))

