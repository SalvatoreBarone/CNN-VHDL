import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate
from matplotlib.lines import Line2D

def plot_hw_resources(csv_file, fpga_pdf):
    width=0.5
    conf = np.genfromtxt(csv_file, delimiter=';', usecols=(0), skip_header=1)
    luts_conv1 = np.genfromtxt(csv_file, delimiter=';', usecols=(3), skip_header=1) / 1000
    luts_conv2 = np.genfromtxt(csv_file, delimiter=';', usecols=(4), skip_header=1) / 1000
    luts_conv3 = np.genfromtxt(csv_file, delimiter=';', usecols=(5), skip_header=1) / 1000
    luts_fc1 = np.genfromtxt(csv_file, delimiter=';', usecols=(6), skip_header=1) / 1000
    luts_fc2 = np.genfromtxt(csv_file, delimiter=';', usecols=(7), skip_header=1) / 1000
    lines = [
       Line2D([0], [0], color='slategray', lw=4),
       Line2D([0], [0], color='mediumseagreen', lw=4), 
       Line2D([0], [0], color='dodgerblue', lw=4),
       Line2D([0], [0], color='crimson', lw=4),
       Line2D([0], [0], color='gold', lw=4)]
    plt.figure(figsize=[6, 3])
    plt.bar(conf, luts_conv1 , width, color='slategray')
    plt.bar(conf, luts_conv2, width, bottom=luts_conv1, color='mediumseagreen')
    plt.bar(conf, luts_conv3, width, bottom=luts_conv1+luts_conv2, color='dodgerblue')
    plt.bar(conf, luts_fc1, width, bottom=luts_conv1+luts_conv2+luts_conv3, color='crimson')
    plt.bar(conf, luts_fc2, width, bottom=luts_conv1+luts_conv2+luts_conv3+luts_fc1, color='gold')
    plt.ylabel('Required LUTs (in thousands)')
    plt.xlabel('#Approx. Configuration')
    labels = ["Exact"] + [ '#'+str(i) for i in range(1, int(np.max(conf)+1))]
    plt.xticks(np.arange(np.max(conf)+1), labels, rotation=90)
    plt.legend(lines, ('Conv1', 'Conv2', 'Conv3', 'FC1', 'FC2'), frameon=False, loc='upper center', ncol=5, bbox_to_anchor=(0.2, 0.62, 0.5, 0.5))
    plt.savefig(fpga_pdf, bbox_inches='tight', pad_inches=0)
    
def plot_power(csv_file, plot_pdf):
    width=0.5
    lines = [
       Line2D([0], [0], color='slategray', lw=4),
       Line2D([0], [0], color='mediumseagreen', lw=4), 
       Line2D([0], [0], color='dodgerblue', lw=4),
       Line2D([0], [0], color='crimson', lw=4),
       Line2D([0], [0], color='gold', lw=4)]
    conf = np.genfromtxt(csv_file, delimiter=';', usecols=(0), skip_header=1)
    pwr_conv1 = np.genfromtxt(csv_file, delimiter=';', usecols=(17), skip_header=1) / 1000
    pwr_conv2 = np.genfromtxt(csv_file, delimiter=';', usecols=(18), skip_header=1) / 1000
    pwr_conv3 = np.genfromtxt(csv_file, delimiter=';', usecols=(19), skip_header=1) / 1000
    pwr_fc1 = np.genfromtxt(csv_file, delimiter=';', usecols=(20), skip_header=1) / 1000
    pwr_fc2 = np.genfromtxt(csv_file, delimiter=';', usecols=(21), skip_header=1) / 1000
    plt.figure(figsize=[6, 3])
    plt.bar(conf, pwr_conv1 , width, color='slategray')
    plt.bar(conf, pwr_conv2, width, bottom=pwr_conv1, color='mediumseagreen')
    plt.bar(conf, pwr_conv3, width, bottom=pwr_conv1+pwr_conv2, color='dodgerblue')
    plt.bar(conf, pwr_fc1, width, bottom=pwr_conv1+pwr_conv2+pwr_conv3, color='crimson')
    plt.bar(conf, pwr_fc2, width, bottom=pwr_conv1+pwr_conv2+pwr_conv3+pwr_fc1, color='gold')
    plt.ylabel('Power consumption (mW)')
    plt.xlabel('#Approx. Configuration')
    labels = ["Exact"] + [ '#'+str(i) for i in range(1, int(np.max(conf)+1))]
    plt.xticks(np.arange(np.max(conf)+1), labels, rotation=90)
    plt.legend(lines, ('Conv1', 'Conv2', 'Conv3', 'FC1', 'FC2'), frameon=False, loc='upper center', ncol=5, bbox_to_anchor=(0.2, 0.62, 0.5, 0.5))
    plt.savefig(plot_pdf, bbox_inches='tight', pad_inches=0)

plot_hw_resources('results.csv', 'lenet5_mulonly_8bits_luts.pdf')
plot_power('results.csv', 'lenet5_mulonly_8bits_power.pdf')
