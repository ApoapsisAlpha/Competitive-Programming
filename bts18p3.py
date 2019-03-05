n, x = input().split()
n = int(n)
x = int(x)
m = [int(i) for i in input().split()]
m.sort(reverse=True)

i = 0
res = 0

while x > 0:
    res += max(0, m[i])
    m[i] -= 1
    x -= 1

    if m[i % n] < m[(i+1) % n]:
        i = (i+1) % n

print(res)