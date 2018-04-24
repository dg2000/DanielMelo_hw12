import numpy as np

import matplotlib.pyplot as plt


x = np.loadtxt("advection.txt")[:, 0]

original = np.loadtxt("advection.txt")[:, 1]

segundo = np.loadtxt("advection.txt")[:, 2]

tercero = np.loadtxt("advection.txt")[:, 3]

cuarto = np.loadtxt("advection.txt")[:, 4]

final = np.loadtxt("advection.txt")[:, 5]




plt.plot(x, original, label="original")

plt.plot(x, segundo, label="segundo")
plt.plot(x, tercero, label="tercero")
plt.plot(x, cuarto, label="cuarto")
plt.plot(x, final, label="final")
plt.ylim(0.0, 0.7)
plt.title("Advection")
plt.xlabel("x")
plt.ylabel("y")

plt.legend(loc=0)


plt.show()
