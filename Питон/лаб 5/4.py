def alphabet():
    for i in range(ord('а'), ord('е') + 1):
        yield chr(i)
    yield 'ё'
    for i in range(ord('ж'), ord('я') + 1):
        yield chr(i)


print(*alphabet())
