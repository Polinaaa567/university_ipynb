alphabet1 = [chr(i) for i in range(ord('а'), ord('ж'))]
alphabet2 = [chr(i) for i in range(ord('ж'), ord('я') + 1)]
print(*alphabet1, 'ё', *alphabet2)
