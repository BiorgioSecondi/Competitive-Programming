import matplotlib.pyplot as plt
from numpy import *

def seq(beta):
    res=0
    x=1
    for i in range(1000):
        res += x
        x = x - (x**beta)/2
    return res

y = [seq(t) for t in linspace(1,2,1000)]
plt.plot(linspace(1,2,1000),y)
plt.show()
