import numpy as np
import pylab as pl

tempFile = open("output/temperature.out")
temps = tempFile.readlines()
tempFile.close()

energyFile = open("output/energy.out")
energies = energyFile.readlines()
energyFile.close()

pl.figure(1)
pl.plot(temps)

pl.figure(2)
pl.plot(energies)

pl.show()
