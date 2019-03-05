a = input().split();
s = []

for i in a:
    if i == "+":
        b = s.pop()
        a = s.pop()
        s.append(a + b)
    elif i == "-":
        b = s.pop()
        a = s.pop()
        s.append(a - b)
    elif i == "*":
        b = s.pop()
        a = s.pop()
        s.append(a * b)
    elif i == "/":
        b = s.pop()
        a = s.pop()
        s.append(a / b)
    elif i == "%":
        b = s.pop()
        a = s.pop()
        s.append(a % b)
    elif i == "^":
        b = s.pop()
        a = s.pop()
        s.append(a ** b)
    else:
        s.append(int(i))
    
print(s[0])