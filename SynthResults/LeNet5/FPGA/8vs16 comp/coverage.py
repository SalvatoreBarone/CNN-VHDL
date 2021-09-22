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

otto_bits = np.genfromtxt('8bits.csv', delimiter=';', usecols=(1, 8, 22), skip_header=1)
sedici_bits = np.genfromtxt('16bits.csv', delimiter=';', usecols=(1, 8, 22), skip_header=1)

print("C(8,16) ", coverage_set(otto_bits, sedici_bits))
print("C(16,8) ", coverage_set(sedici_bits, otto_bits))


