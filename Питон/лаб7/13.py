import random

file = open('lines.txt', encoding='utf8')
file2 = file.read()
line = file2.split('\n')

print(random.choice(line))
