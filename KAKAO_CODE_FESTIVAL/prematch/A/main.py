


from sys import stdin

n = int(stdin.readline())


win17 = [0] + [500] + (2 * [300]) + (3 * [200]) + (4 * [50]) + (5 * [30]) + (6 * [10]) + (100 * [0])

win18 = [0] + [512] + (2 * [256]) + (4 * [128]) + (8 * [64]) + (16 * [32]) + (100 * [0])



for i in range(n):
    m, n = list(map(int, stdin.readline().split(" ")))

    output = win17[m] + win18[n]
    output = output * 10000

    print(output)



