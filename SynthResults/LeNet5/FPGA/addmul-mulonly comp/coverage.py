import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate
from matplotlib.lines import Line2D

def coverage_set(set_A, set_B):
    count = 0
    for b in set_B:
        for a in set_A:
            if a[0] <= b[0] and a[1] <= b[1] and a[2] <= b[2]:
                count = count + 1
                break
    return count / len(set_B)

add_mul = np.genfromtxt('addMul.csv', delimiter=';', usecols=(1, 8, 22), skip_header=1)
mul_only = np.genfromtxt('mulOnly.csv', delimiter=';', usecols=(1, 8, 22), skip_header=1)

print(add_mul)
print(mul_only)

print("C(add_mul, mul_only) ", coverage_set(add_mul, mul_only))
print("C(mul_only, add_mul) ",coverage_set(mul_only, add_mul))


