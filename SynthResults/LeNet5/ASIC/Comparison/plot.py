#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines

def plot_scatter(data_circ, data_scale, ylabel, pdf_file):
    width = 0.5

    legend_markers = [
            mlines.Line2D([],[], color='black',   marker='*', linestyle='None', label='Reference'),
            mlines.Line2D([],[], color='tab:blue', marker='.', linestyle='None', label='Ax-Circuits'),
            mlines.Line2D([],[], color='tab:red',  marker='d', linestyle='None', label='Precision-scaling')
            ]
    circ_error = data_circ[:,0]
    circ_conv1 = data_circ[:,1]
    circ_conv2 = data_circ[:,2]
    circ_conv3 = data_circ[:,3]
    circ_fc1   = data_circ[:,4]
    circ_fc2   = data_circ[:,5]
    circ_total = circ_conv1 + circ_conv2 + circ_conv3 + circ_fc1 + circ_fc2

    scale_error = data_scale[:,0]
    scale_conv1 = data_scale[:,1]
    scale_conv2 = data_scale[:,2]
    scale_conv3 = data_scale[:,3]
    scale_fc1   = data_scale[:,4]
    scale_fc2   = data_scale[:,5]
    scale_total = scale_conv1 + scale_conv2 + scale_conv3 + scale_fc1 + scale_fc2

    fig = plt.figure(figsize=[6,3])
    plt.xlabel('Accuracy Loss (%)')
    plt.ylabel(ylabel)
    plt.scatter(circ_error, circ_total, marker='.', color='tab:blue')
    plt.scatter(scale_error[1:], scale_total[1:], marker='d', color='tab:red')
    plt.scatter(scale_error[0], scale_total[0], marker='*', color='black')

    

    plt.legend(handles=legend_markers, frameon=False, loc='upper right', ncol=1)
    plt.tight_layout()
    plt.savefig(pdf_file, pad_inches=0)


circ_data = np.genfromtxt('evoapprox_summary.csv', delimiter=';', usecols=(0,1,2,3,4,5), skip_header=1)
scale_data = np.genfromtxt('scaling_summary.csv', delimiter=';', usecols=(0,1,2,3,4,5), skip_header=1)
plot_scatter(circ_data, scale_data, 'Circuit Area (um²)', 'lenet5_circ_scale_pareto_area.pdf')

circ_data = np.genfromtxt('evoapprox_summary.csv', delimiter=';', usecols=(0,6,7,8,9,10), skip_header=1)
scale_data = np.genfromtxt('scaling_summary.csv', delimiter=';', usecols=(0,6,7,8,9,10), skip_header=1)
plot_scatter(circ_data, scale_data, 'Power Consumption (nW)', 'lenet5_circ_scale_pareto_power.pdf')
 
