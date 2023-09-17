def square_fibonacci(n):
    result1, result2 = 0, 1
    for i in range(n):
        yield result2 ** 2
        result1, result2 = result2, result1 + result2


print(*square_fibonacci(7))
