import numpy as np
import pylab as pl

f = open("data.out")
lines = f.readlines()
f.close()

pl.plot(lines)
pl.show()