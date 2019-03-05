n = int(input())
a = [int(i) for i in input().split()]


def is_sorted(c):
    for i in range(len(c)-2):
        if c[i] > c[i+1]:
            return False

    return True


found_wildcard = False
fw = -1
replacement = 0
for i in range(n):
    if a[i] == 0:
        if fw == -1:
            fw = i
        found_wildcard = True

    elif found_wildcard:
        replacement = a[i]
        break

    if found_wildcard and i == n - 1:
        if fw != n - 1:
            replacement = a[fw + 1]
        else:
            replacement = a[fw - 1]

if found_wildcard:
    a = [replacement if x == 0 else x for x in a]

if is_sorted(a):
    print('YES')
else:
    print('NO')