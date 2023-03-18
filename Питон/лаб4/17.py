def linear(some_list):
    if type(some_list) is list:
        if len(some_list) == 1:
            return linear(some_list[0])
        elif len(some_list) > 1:
            # Для простоты, выделим рекурсивный ответ для первого и всех оставшихся элементов списка
            # Каждый из возвращенных из рекурсий ответов ans1 и ans2 может представлять собой или список,
            # или отдельное не списковое значение.
            # Если вернется список, то мы должны раскрыть его с помощью extend, если значение - просто добавить его к результируещему ans
            ans = []
            ans1 = linear(some_list[0])
            ans.append(ans1) if type(ans1) is not list else ans.extend(ans1)
            ans2 = linear(some_list[1:])
            ans.append(ans2) if type(ans2) is not list else ans.extend(ans2)
            return ans
        else:
            return []
    else:
        return some_list


print(*linear([[1, 2], 4, [[2, 4, 8, [-4, "er", [0], [{2: "primer"}], []]]]]))
print(*linear([[], [[], "EW"], [[[]]], [[[[[[[[[[[1, ]]], 25, ]]]]]]]]]))


'''
            # альтернативный вариант с уменьшением кол-ва рек. вызовов
            # НЕ РАБОТАЕТ!!!
            ans = []
            if type(some_list[0]) is not list:
                ans.append(some_list[0])
            else:
                ans.extend(linear(some_list[0]))
            if len(some_list[1:]) == 1 and type(some_list[1]) is not list:
                ans.append(some_list[1])
            else:
                ans.extend(linear(some_list[1:]))
            '''