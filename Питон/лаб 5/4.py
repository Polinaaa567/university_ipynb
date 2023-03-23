def alphabet():
    for i in range(ord('а'), ord('я') + 1):
        yield chr(i)


print(*alphabet())
