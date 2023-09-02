list = [1, -4, -7, 2, 9, -3, 40, -10, -4, 9, 0]

for i in range(0, len(list) - 1, 2):
    list[i], list[i + 1] = list[i + 1], list[i]
print(list)
