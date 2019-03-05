n = int(input())
    
def is_prime(n):
    if n <= 1: return False
    for i in range(2, n):
        if n % i == 0: return False

    return True

for i in range(n):
    c = 0
    x, y = map(int, input().split())
    
    for j in range(x, y):
        if (is_prime(j)):
            c += 1

    print(c)