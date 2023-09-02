list1 = []
list2 = []

for i in range(8):
    list3, list4 = [int(j) for j in input().split()]
    list1.append(list3)
    list2.append(list4)
res = True

for i in range(8):
    for j in range(i + 1, 8):
        if list1[i] == list1[j] or list2[i] == list2[j] \
                or abs(list1[i] - list1[j]) == abs(list2[i] - list2[j]):
            res = False
if res:
    print("NO")
else:
    print("Yes")
