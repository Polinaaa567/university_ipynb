stroka = input().split()

count = {}

for word in stroka:
    count[word] = count.get(word, 0) + 1

print(count)