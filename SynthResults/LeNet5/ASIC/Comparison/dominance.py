import numpy as np

def coverage(A_set, B_set):
    dom = 0
    for i in range B_set.shape[0]:
        for j in range A_set.shape[0]:
            if all(A[j] <= B[i]) #and any (A[j] < B[j]):
                dom = dom + 1
    return dom / B_set.shape[0]


