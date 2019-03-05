n, m, k, v = map(int, input().split())
count = 0
while (v):
    v &= v-1
    count += 1

print(pow(pow(2,n-1,m),k,m))
print(pow(pow(2,n,m)-1,count,m))
print(pow(pow(2,n,m)-1,(k-count),m))