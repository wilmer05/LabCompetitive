from sys import stdin

for line in stdin:
    n, k = line.split()
    k = int(k)
    n = int(n)

    ans = 0
    for i in range(1,n + 1):
        ans += i * (k ** i)
    print(ans)
