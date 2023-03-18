N = int(input())
a = set()
b = set()
k = 0

for i in range(N):
    fam = input()
    if fam not in a:
        a.add(fam)
    else:
        k += 1
        if fam not in b:
            b.add(fam)

k += len(b)
print(k)
