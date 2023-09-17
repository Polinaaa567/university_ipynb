n = int(input())
zvezda = 1

while n - 1 >= 0:
    print(" " * n + "*" * zvezda)
    zvezda += 2
    n -= 1
