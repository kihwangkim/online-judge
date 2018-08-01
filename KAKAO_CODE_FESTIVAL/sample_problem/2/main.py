


from sys import stdin

import itertools



friends = ["A", "C", "F", "J", "M", "N", "R", "T"]

candidates = itertools.permutations(friends, len(friends))

#for line in candidates:
#    print(line)




n = int(stdin.readline())




v = list()
for _ in range(n):
    line = stdin.readline()
    v.append(line)


number = 0
for candidate in candidates:
    f = True
    for line in v:
        a = line[0]
        b = line[2]
        s = line[3]
        n = int(line[4]) + 1

        a_index = candidate.index(a)
        b_index = candidate.index(b)
        if s == "=":
            if not abs(a_index - b_index) == n:
                f = False
                break
        elif s == ">":
            if not abs(a_index - b_index) > n:
                f = False
                break
        elif s == "<":
            if not abs(a_index - b_index) < n:
                f = False
                break
    if f == True:
        number += 1

print(number)
    
    




