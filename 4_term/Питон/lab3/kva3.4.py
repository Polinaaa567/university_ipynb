my_list = input().split()

my_set = set()

for number in my_list:
    if number in my_set:
        print("yes")
    else:
        print("no")
        my_set.add(number)