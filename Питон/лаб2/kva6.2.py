list = [1, -4, -7, 2, 9, -3, 40, -10, -4, 9]

for i in range(1, len(list)):
    if list[i - 1] * list[i] > 0:
        print(list[i - 1], list[i])
        break
