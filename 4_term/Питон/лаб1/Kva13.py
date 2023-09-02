n = int(input())
m = int(input())
symb = input()

print(symb * m)
for i in range(n - 2):
    print(symb, ' ' * (m - 2), symb, sep="")
print(symb * m)
