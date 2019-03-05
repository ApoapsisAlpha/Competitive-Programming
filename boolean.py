words = raw_input().split()

if words[-1] == 'True':
    if len(words) % 2 == 0:
        print 'False'
    else:
        print 'True'
else:
    if len(words) % 2 == 0:
        print 'True'
    else:
        print 'False'