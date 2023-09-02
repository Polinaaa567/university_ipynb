def partial_sums(*value):
    res = [0]
    for i in range(len(value)):
        res.append(res[i] + value[i])
    return res


print(partial_sums(13, 9, 4))
