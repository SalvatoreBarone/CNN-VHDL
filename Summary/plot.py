import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate
from matplotlib.lines import Line2D

def plot_data(csv_file, width, axes, label):
    conf = np.genfromtxt(csv_file, delimiter=',', usecols=(0), skip_header=1)
    conv1 = np.genfromtxt(csv_file, delimiter=',', usecols=(1), skip_header=1)
    conv2 = np.genfromtxt(csv_file, delimiter=',', usecols=(2), skip_header=1)
    conv3 = np.genfromtxt(csv_file, delimiter=',', usecols=(3), skip_header=1)
    fc1 = np.genfromtxt(csv_file, delimiter=',', usecols=(4), skip_header=1)
    fc2 = np.genfromtxt(csv_file, delimiter=',', usecols=(5), skip_header=1)
    axes.bar(conf, conv1 , width, color='tab:blue')
    axes.bar(conf, conv2, width, bottom=conv1, color='tab:orange')
    axes.bar(conf, conv3, width, bottom=conv1+conv2, color='tab:green')
    axes.bar(conf, fc1, width, bottom=conv1+conv2+conv3, color='tab:brown')
    axes.bar(conf, fc2, width, bottom=conv1+conv2+conv3+fc1, color='tab:purple')
    axes.set_ylabel(label)
    axes.set_xlabel('#Approx. Configuration')
    
def plot_result(luts_csv, ffs_csv, outfile):
    lines = [
       Line2D([0], [0], color='tab:blue', lw=4),
       Line2D([0], [0], color='tab:orange', lw=4), 
       Line2D([0], [0], color='tab:green', lw=4),
       Line2D([0], [0], color='tab:brown', lw=4),
       Line2D([0], [0], color='tab:purple', lw=4)]

    area_img, axes = plt.subplots(2,1, sharex=True, figsize=(12, 10))
    plot_data(luts_csv, 0.5, axes[0], 'Required LUTs')
    plot_data(ffs_csv, 0.5, axes[1], 'Required FFs')
    area_img.legend(lines, ('Conv1', 'Conv2', 'Conv3', 'FC1', 'FC2'), loc='upper right', ncol=1)
    area_img.legend()
    area_img.tight_layout()
    area_img.savefig(outfile, bbox_inches='tight', pad_inches=0)

plot_result('16bits_luts.csv', '16bits_registers.csv', '16bits.pdf')
