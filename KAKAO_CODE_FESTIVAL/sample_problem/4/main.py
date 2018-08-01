


from sys import stdin

import sys

line = list(stdin.readline().strip())


mapping = dict()
for i, ch in enumerate(line):
    mapping[ch] = mapping.setdefault(ch, list()) + [i]



new_line = []
stack = []
i = 0
flag = True
while True:
    if i == len(line):
        if not len(stack) == 0:
            new_line.append(stack[:])
        break

    ch = line[i]

    flag = True
    if ch.islower() and len(mapping[ch]) != 2:
        if len(stack) == 0:
            flag = False
            break
        last_ch = stack.pop()
        if not len(stack) == 0:
            new_line.append(stack[:])
        stack = []
        stack.append(last_ch)

        for j in range(len(mapping[ch]) - 1):
            if not mapping[ch][j] + 2 == mapping[ch][j + 1]:
                flag = False
                break

        if flag == False:
            # invalid
            break

        i -= 1
        for _ in range(len(mapping[ch])):
            i += 2
            stack.append(line[i])

        
        if len(list(filter(lambda x: x.islower(), stack))):
            flag = False
            break

        new_line.append(stack[:])
        stack = []
        i += 1

        if len(new_line) != 0 and len(new_line[-1]) != 0 and new_line[-1][-1].islower() and new_line[-1][-1] == line[i]:
            new_line[-1].pop()
            i += 1
    else:
        if i + 6 < len(line) and line[i].islower() and line[i] == line[i + 6] and line[i + 2].islower() and line[i + 2] == line[i + 4]:
            if line[i + 1].isupper() and line[i + 3].isupper() and line[i + 5].isupper():
                if not len(stack) == 0:
                    new_line.append(stack[:])
                    stack = []
                new_line.append(line[i + 1:i + 6:2])
                i += 7
        else:
            stack.append(line[i])
            i += 1



if flag == False:
    print("invalid")
    sys.exit()



words = []
for word in new_line:
    if len(word) == 0:
        continue

    if len(list(filter(lambda x: x.islower(), word))) == 0:
        words.append(word[:])
        continue

    wflag = False
    last_ch = ""
    stack = []
    for ch in word:
        if ch.islower() == True:
            if wflag == False:
                if not len(stack) == 0:
                    words.append(stack[:])
                    stack = []
                last_ch = ch
                wflag = True
            else:
                if last_ch == ch:
                    words.append(stack[:])
                    stack = []
                    wflag = False
                    continue
                else:
                    flag = False
                    break
        else:
            stack.append(ch)

    if not len(stack) == 0:
        words.append(stack[:])




if flag == False:
    print("invalid")
    sys.exit()


for i, word in enumerate(words):
    for ch in word:
        print(ch, end='')
    if not i + 1 == len(words):
        print(" ", end='')

print()


