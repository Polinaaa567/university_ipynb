s = input()

s1 = s.find('f')
s2 = s.count('f')
s3 = s.rfind('f')

if s2 == 0:
    print()
elif s2 == 1:
    print(s1)
else:
    print(s1, s3)
