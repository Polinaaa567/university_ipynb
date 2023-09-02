list = [1, -4, -7, 2, 9, -3, 40, -10, -4, 9, 1]

print(list)
for i in range(0, len(list)):
    if list.count(list[i]) == 1:
        print(list[i])
