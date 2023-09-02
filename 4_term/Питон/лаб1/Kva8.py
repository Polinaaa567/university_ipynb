count = 0
minn = 200
maxx = 0
while True:
    height = input()
    if height == '!':
        break
    height = int(height)
    if 190 > height > 150:
        count += 1
        if minn > height:
            minn = height
        if maxx < height:
            maxx = height

print(count)
print(minn, maxx)
