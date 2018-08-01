


from sys import stdin

line = stdin.readline()


m, n = map(int, line.split(' '))



reverse_data = dict()
map_data = list()
for m_index in range(m):
    line = stdin.readline().strip()
    map_data += [list(line)]
    for n_index, c in enumerate(line):
        reverse_data[c] = reverse_data.setdefault(c, []) + [(m_index, n_index)]




keys = list(reverse_data.keys())

if "." in keys:
    keys.remove(".")
if "*" in keys:
    keys.remove("*")

keys.sort()




stack = keys[:]
stack.reverse()
match = []

while True:
    if len(stack) == 0:
        answer = 0
        break
    key = stack.pop()
    if key in match:
        continue

    def check_x(a, b, x):
        c = min(a, b)
        d = max(a, b)

        for i in range(c + 1, d):
            if map_data[x][i] != ".":
                return False
        return True


    def check_y(a, b, y):
        c = min(a, b)
        d = max(a, b)

        for i in range(c + 1, d):
            if map_data[i][y] != ".":
                return False
        return True

    a, b = reverse_data[key]

    ax, ay = a
    bx, by = b

    if ax == bx:
        flag = check_x(ay, by, ax)
    elif ay == by:
        flag = check_y(ax, bx, ay)
    else:
        flag = (check_x(ay, by, ax) and check_y(ax, bx, by) and map_data[ax][by] == ".") or (check_x(ay, by, bx) and check_y(ax, bx, ay) and map_data[bx][ay] == ".")

    if flag == True:
        map_data[ax][ay] = "."
        map_data[bx][by] = "."
        match.append(key)

        stack += [key]
        temp = keys[:]
        temp.remove(key)
        temp.reverse()
        stack += temp

    elif len(match) > 0:
        if match[-1] == stack[-1]:
            last_key = match[-1]
            a, b = reverse_data[last_key]
            map_data[a[0]][a[1]] = last_key
            map_data[b[0]][b[1]] = last_key
            match.pop()
            stack.pop()


    if len(match) == len(keys):
        answer = match
        break



if answer == 0:
    print("IMPOSSIBLE")
else:
    for k in match:
        print(k, end='')
    print()
