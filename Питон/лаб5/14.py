from sys import stdin

lines = ''
for line in stdin:
    lines += line

result = {}

for i, val in enumerate(lines.split(), start=0):
    if val[0].isupper() and val not in result:
        result[val] = i

for i, val in sorted(result.items()):
    print(f' {val} - {i}')
# Ехал Грека через реку
# Видит Грека в реке рак
# Сунул в реку руку Грека
# Рак за руку Греку цап
