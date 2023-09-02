n = int(input())
c = 1
kva = 1
oh = 0

while (c <= n):
    print(c, end=" ")
    c += 1
    oh += 1
    if (oh == kva):
        print()
        kva += 1
        oh = 0