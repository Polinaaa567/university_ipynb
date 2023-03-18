number_strok = int(input())

my_set = set()

for i in range(number_strok):
    my_set.update(input().split())

print(len(my_set))
