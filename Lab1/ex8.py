from sys import stdin
from math import sqrt

def check_sol(U, V, W, x, y, z):
    return x + y + z == U and x * y * z == V and x ** 2 + y ** 2 + z ** 2 == W and x < y and y < z

T = None
mn = 5 * (10 ** 6)
for line in stdin:
    if T is None:
        T = int(line)
        continue
    else:
        U, V, W = line.split()
    U = int(U)
    V = int(V)
    W = int(W)
    x = None
    y = None
    z = None
    for i in range(1, min(mn, min(V, min(W, U)))):

        tmp_u = U - i
        if V % i != 0:
            continue
        tmp_v = V / i
        if i > U or i * i > W:
            break

        if tmp_u ** 2 < 4 * tmp_v:
            continue
        det = tmp_u ** 2 - 4 * tmp_v
        if int(sqrt(det)) != sqrt(det):
            continue

        root_1 = (tmp_u - sqrt(det)) / 2
        root_2 = (tmp_u + sqrt(det)) / 2

        if int(root_1) == root_1 and root_1 > i:
            k = tmp_u - root_1
            if check_sol(U, V , W, i, root_1, k):
               x = i
               y = root_1
               z = k
               break

        if int(root_2) == root_2 and root_2 > i:
            k = tmp_u - root_2
            if check_sol(U, V, W, i, root_2, k):
               x = i
               y = root_2
               z = k
               break

    if x is None:
        print("empty set")
    else:
        print("{} {} {}".format(int(x), int(y), int(z)))
