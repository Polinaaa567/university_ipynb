my_list = [i for i in range(5) if i < 5]
print(my_list)

my_list = [i for i in range(5) if i % 2 == 0]
print(my_list)

my_list = [int(i) * 2 for i in range(11) if i * 2 > 17]
print(my_list)

my_list = [int(i) ** 2 for i in range(int(input()))]
print(my_list)

my_list = [int(i) ** 2 for i in input().split()]
print(my_list)

my_list = [int(i) ** 2 for i in input().split() if int(i) % 2 != 0 and str(int(i) ** 2)[-1] != '9']
print(my_list)
