string = input().split()
print(' '.join(sorted(string, key=lambda x: x.lower())))
