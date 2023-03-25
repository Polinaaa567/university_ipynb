def factorials(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
        yield result


print(*factorials(5))