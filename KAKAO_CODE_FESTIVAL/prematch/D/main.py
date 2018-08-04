


from sys import stdin
import sys

N, Q = list(map(int, stdin.readline().split(" ")))


point = []
point_x_dict = dict()
point_y_dict = dict()
for i in range(N):
    x, y = list(map(int, stdin.readline().split(" ")))
    point.append((x, y))
    point_x_dict[x] = point_x_dict.get(x, list()) + [i]
    point_y_dict[y] = point_y_dict.get(y, list()) + [i]



def get_possible(start, X):
    x = point[start][0]
    y = point[start][1]
    
    possible = set()
    for i in range(x - X if x >= X else 0, x + X + 1):
        t = point_x_dict.get(i, [])
        possible.update(t)
    for i in range(y - X if y >= X else 0, y + X + 1):
        t = point_y_dict.get(i, [])
        possible.update(t)
    
    if start in possible:
        possible.remove(start)

    return possible

class Graph:
    def __init__(self, HP):
        self.HP = HP
        self.make_graph()

    def make_graph(self):
        HP = self.HP

        self.map = [ 0 for _ in range(N) ]
        for p in range(N):
            self.map[p] = get_possible(p, self.HP)


graphs = dict()
for i in range(Q):
    A, B, X = list(map(int, stdin.readline().split(" ")))
    
    a = A - 1
    b = B - 1

    if not graphs.get(X):
        graphs[X] = Graph(X)
    graph = graphs[X]


    instack = set()
    stack = []

    stack.append(a)
    instack.add(a)

    flag = False
    while True:
        if len(stack) == 0:
            flag = False
            break
        p = stack[0]
        stack.remove(p)
        if p == b:
            flag = True
            break
        possible_set = graph.map[p] - instack
        if b in possible_set:
            flag = True
            break
        stack.extend(list(possible_set))
        instack = instack.union(possible_set)

    if flag == True:
        print("YES")
    else:
        print("NO")
    



#    S = min(point[a][0], point[b][0])
#    D = max(point[a][0], point[b][0])
#    while True:
#        Sn = S
#        if abs(S - D) <= X:
#            flag = True
#            break
#        for i in range(X):
#            if len(possible_x[S + X - i]) != 0:
#                Sn = S + X - i
#                break
#        if Sn == S:
#            flag = False
#            break
#        else:
#            continue
#    if flag == True:
#        print("YES")
#        sys.exit()
#
#
#    S = min(point[a][1], point[b][1])
#    D = max(point[a][1], point[b][1])
#    while True:
#        if abs(S - D) <= X:
#            flag = True
#            break
#        for i in range(X):
#            if len(possible_y[S + X - i]) != 0:
#                Sn = S + X - i
#                break
#        if Sn == S:
#            flag = False
#            break
#        else:
#            continue
#    if flag == True:
#        print("YES")
#        sys.exit()
#
#    print("NO")
