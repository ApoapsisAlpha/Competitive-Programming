m = {"Deluxe Tuna Bitz":0, "Bonito Bitz":0, "Sashimi":0, "Ritzy Bitz":0}
a = {"Deluxe Tuna Bitz":4, "Bonito Bitz":3, "Sashimi":2, "Ritzy Bitz":1}
n = int(input())
for i in range(n):
  m[input()] += 1

a = sorted(m.items(), key=lambda x: (x[1],a[x[0]]), reverse=True)
for k,v in a:
  if v == 0: break
  print(k+' '+str(v))