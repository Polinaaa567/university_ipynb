def palindrome(s):
    s = s.replace(' ','').lower()
    return 'Палиндром' if s == s[::-1] else 'Не палиндром'


print(palindrome('1221'))
print(palindrome('А роза упала на лапу Aзора'))