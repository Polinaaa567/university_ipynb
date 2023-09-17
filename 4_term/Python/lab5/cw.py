# n = 14
#
# if n % 2 == 0 and n % 4 ==0:
#     print('good')
# else:
#     print(False)

# 2

# n = [1, 2, 3, 4, 5, 6]
# for i in range(len(n) - 1):
#     if i % 2 == 0:
#         t = n[i]
#         n[i] = n[i + 1]
#         n[i + 1] = t
#
# print(n)

#3
#
# t = [input()]
# print(*' '.join(t))

#4
# summ = 0
# proizv = 1
# kol = 0
# p = int(input())
# h = int(input())
# for i in iter(input()):
#     if i < p:
#         summ+= p
#     elif i > h:
#         proizv*= h
#     else:
#         kol+=1
# print(summ, proizv, kol)