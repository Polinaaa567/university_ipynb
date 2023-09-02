action_perm = {
    "write": "W",
    "read": "R",
    "execute": "X",
}
d = {}
for i in range(int(input())):
    file, *perm = input().split()
    d[file] = set(perm)

for i in range(int(input())):
    action, file = input().split()

    if action_perm[action] in d[file]:
        print("OK")
    else:
        print("Access denied")
