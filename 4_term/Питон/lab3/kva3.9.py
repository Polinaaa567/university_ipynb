N = int(input())
slovar = {}

for i in range(N):
    prezident, value = input().split()

    if prezident in slovar:
        slovar[prezident] += int(value)

    else:
        slovar[prezident] = int(value)

for prezident, value in sorted(slovar.items()):
    print(prezident, value)
