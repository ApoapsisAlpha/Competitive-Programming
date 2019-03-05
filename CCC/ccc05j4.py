width = int(input())
height = int(input())
w = int(input())
h = int(input())
s = int(input())
m = []

for i in range(height+2):
    m.append([])
    for j in range(width+2):
        m[-1].append(0)

for i in range(width+2):
    m[0][i] = 1
    m[height+1][i] = 1
for i in range(height+2):
    m[i][0] = 1
    m[i][width+1] = 1

for i in range(1,h+1):
    for j in range(1,w+1):
        m[i][j] = 1
        m[height-i+1][width-j+1] = 1
        m[height-i+1][j] = 1
        m[i][width-j+1] = 1
x = 1
y = w+1

def spiral(x,y,s,d):
    m[x][y] = 1
    if s == 0:
        return x,y
    if d == 0:
        if m[x][y-1] == 0:
            return spiral(x,y-1,s-1,3)
        elif m[x-1][y] == 0:
            return spiral(x-1,y,s-1,0) 
        elif m[x][y+1] == 0:
            return spiral(x,y+1,s-1,1)
    if d == 1:
        if m[x-1][y] == 0:
            return spiral(x-1,y,s-1,0)
        elif m[x][y+1] == 0:
            return spiral(x,y+1,s-1,1)
        elif m[x+1][y] == 0:
            return spiral(x+1,y,s-1,2)
    if d == 2:
        if m[x][y+1] == 0:
            return spiral(x,y+1,s-1,1)
        elif m[x+1][y] == 0:
            return spiral(x+1,y,s-1,2)
        elif m[x][y-1] == 0:
            return spiral(x,y-1,s-1,3)
    if d == 3:
        if m[x+1][y] == 0:
            return spiral(x+1,y,s-1,2)
        elif m[x][y-1] == 0:
            return spiral(x,y-1,s-1,3)
        elif m[x-1][y] == 0:
            return spiral(x-1,y,s-1,0)
    return x,y

x,y = spiral(x,y,s,1)
 
print(y)
print(x)