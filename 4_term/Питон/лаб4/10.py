def mirror(arr):
    mirrored_part = reversed(arr)
    arr += mirrored_part


arr = [1, 2]
mirror(arr)
print(*arr)

arr = [1]
mirror(arr)
print(*arr)
