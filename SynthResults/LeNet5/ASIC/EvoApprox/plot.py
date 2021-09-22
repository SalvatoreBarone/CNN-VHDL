#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

def plot_bar(data, ylabel, pdf_file):
    width = 0.5
    conv1 = data[:,0]
    conv2 = data[:,1]
    conv3 = data[:,2]
    fc1   = data[:,3]
    fc2   = data[:,4]
    
    print(fc1)
    print(fc2)

    lines = [
       Line2D([0], [0], color='slategray', lw=4),
       Line2D([0], [0], color='mediumseagreen', lw=4), 
       Line2D([0], [0], color='dodgerblue', lw=4),
       Line2D([0], [0], color='crimson', lw=4),
       Line2D([0], [0], color='gold', lw=4)]

    img = plt.figure(figsize=[6,3])
    conf = np.arange(len(data[:,0]))

    plt.bar(conf, conv1 , width, color='slategray')
    plt.bar(conf, conv2, width, bottom=conv1, color='mediumseagreen')
    plt.bar(conf, conv3, width, bottom=conv1+conv2, color='dodgerblue')
    plt.bar(conf, fc1, width, bottom=conv1+conv2+conv3, color='crimson')
    plt.bar(conf, fc2, width, bottom=conv1+conv2+conv3+fc1, color='gold')
    plt.xticks(np.arange(0, len(data[:,0]), step=1))
    plt.ylabel(ylabel)
    plt.xlabel('#Approx. Configuration')
    plt.legend(lines, ('Conv1', 'Conv2', 'Conv3', 'FC1', 'FC2'), frameon=False, bbox_to_anchor=(.5, 1.2), loc='upper center', ncol=5)
    plt.savefig(pdf_file, bbox_inches='tight', pad_inches=0)


data = np.genfromtxt('summary.csv', delimiter=';', usecols=(0,1,2,3,4), skip_header=1)
plot_bar(data, 'Circuit Area (um²)', 'lenet5_asic_area.pdf')
data = np.genfromtxt('summary.csv', delimiter=';', usecols=(5,6,7,8,9), skip_header=1)
plot_bar(data, 'Power Consumption (nW)', 'lenet5_asic_power.pdf')
