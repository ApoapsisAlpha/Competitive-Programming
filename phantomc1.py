print' '.join(`j`+'*'[[i.__setitem__(k,0)for k in i[j*j::j]]<0:i[j-2]|i[j+2]]for i in[range(input())]for j in i if j>1)