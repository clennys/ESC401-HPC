import matplotlib.pyplot as plt
import numpy as np
from matplotlib.colors import LogNorm

with open('data.txt', 'r') as f:
    content = f.read().splitlines()

data = [float(el) for el in content]

counter = 0
matrix = []
row = []
for el in data:
    if counter == 10:
        counter = 0;
        matrix.append(row)
        row = []
    row.append(el)
    counter += 1


matrix.append(row)

plt.ylabel("Blocks")
plt.xlabel("Threads")
plt.pcolormesh(matrix)

for row in matrix:
    print(row)
  
plt.title('Cuda Thread vs Blocks', fontweight ="bold")
plt.show()
