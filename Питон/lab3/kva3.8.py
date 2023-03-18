N = int(input())

slovar = {}

for word in range (N):
    my_slovar = input().split()
    slovar[my_slovar[0]] = my_slovar[1]
    slovar[my_slovar[1]] = my_slovar[0]

print(slovar[input()])