def recurse_len(some_list):
    if some_list:
        return 1 + recurse_len(some_list[1:])
    else:
        return 0


print(recurse_len([1, 2, 3]))
