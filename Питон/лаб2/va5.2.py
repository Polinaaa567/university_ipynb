a = input().lower()

while True:
    b = input().lower()
    if a[-1] != b[0]:
        print(b)
        break
    a = b