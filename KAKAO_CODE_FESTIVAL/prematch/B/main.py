


from sys import stdin

import sys


N, K = list(map(int, stdin.readline().split(' ')))

D = list(map(int, stdin.readline().split(' ')))

D_sum = [0]
D_sum_2 = [0]
for i in D:
    d = D_sum[-1]
    D_sum.append(i + d)
    t = D_sum_2[-1]
    D_sum_2.append(pow(i, 2) + t)

def v(start, end):
    avg = (D_sum[end] - D_sum[start]) / (end - start)
    avg_2 = (D_sum_2[end] - D_sum_2[start]) / (end - start)
    return pow(avg_2 - pow(avg, 2), 0.5)

flag = False
for k in range(K, N + 1):
    for i in range(N - k + 1):
        d = v(i, i + k)
        if flag == False:
            result = d
            flag = True
        else:
            result = min(result, d)

print("%.20f"%result)





