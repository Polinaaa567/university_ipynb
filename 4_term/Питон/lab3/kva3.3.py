list1 = [1, 2, 3, 4, 10, 6]
list2 = [4, 7, 8, 2, 1, 5]

print(*sorted(set(list1) | set(list2)))
