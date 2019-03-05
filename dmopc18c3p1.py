m = {'A':0,'A#':1,'B':2,'C':3,'C#':4,'D':5,'D#':6,'E':7,
  'F':8,'F#':9,'G':10,'G#':11}

def interval(a, b):
    d = (m[b] - m[a] + 12) % 12
    return d

k1 = raw_input()
k2 = raw_input()
k3 = raw_input()
f = k1
d1 = interval(k1, k2)
d2 = interval(k2, k3)

c = 0

if not ((d1 == 4 and d2 == 3) or (d1 == 3 and d2 == 4) or (d1 == 4 and d2 == 4) or (d1 == 3 and d2 == 3)):
    d1 = interval(k2, k3)
    d2 = interval(k3, k1)
    c = 1
    f = k2

if not ((d1 == 4 and d2 == 3) or (d1 == 3 and d2 == 4) or (d1 == 4 and d2 == 4) or (d1 == 3 and d2 == 3)):
    d1 = interval(k3, k1)
    d2 = interval(k1, k2)
    c = 2
    f = k3

print f

if d1 == 4 and d2 == 3:
    print 'major'
elif d1 == 3 and d2 == 4:
    print 'minor'
elif d1 == 4 and d2 == 4:
    print 'augmented'
elif d1 == 3 and d2 == 3:
    print 'diminished'

if c == 0:
    print 'root position'
elif c == 2:
    print 'first inversion'
else:
    print 'second inversion'