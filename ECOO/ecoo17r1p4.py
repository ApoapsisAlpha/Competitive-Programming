for t in range(10):
    n = int(input())
    ans = 100000000
    names = [(input(), i) for i in range(n)]
    for rm in names:
        vis = [0]*n
        swaps = 0
        names2 = []
        for name in names:
            if name[1] > rm[1]:
                names2.append((name[0], name[1]-1))
            elif name[1] < rm[1]:
                names2.append(name)

        names2.sort()
        for i in range(n-1):
            if vis[i] or names2[i][1] == i: continue
            cycle = 0
            cur = i
            while not vis[cur]:
                vis[cur] = 1
                cycle += 1
                cur = names2[cur][1]

            swaps += max(0, cycle-1)
        ans = min(ans, swaps)
    print(ans)
