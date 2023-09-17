list = [1, 4, 7, 2, 9, 3, 40, 10, 4, 9]

for i in range(1, len(list)):
    if list[i] > list[i - 1]:
        print(list[i])
