import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate
from matplotlib.lines import Line2D

def plot_hw_resources(csv_file, pareto_pdf, fpga_pdf):
    width=0.5
    conf = np.genfromtxt(csv_file, delimiter=',', usecols=(0), skip_header=1)
    error = np.genfromtxt(csv_file, delimiter=',', usecols=(1), skip_header=1)
    reward = np.genfromtxt(csv_file, delimiter=',', usecols=(2), skip_header=1)

    plt.figure(figsize=[5,5])
    plt.plot(error, reward*100, 'k.')
    plt.plot(np.array(0), np.array(0), 'g*')
    plt.xlabel('Error (%)')
    plt.ylabel('Reward (%)')
    plt.tight_layout()
    plt.savefig(pareto_pdf, bbox_inches='tight', pad_inches=0)

    luts_conv1 = np.genfromtxt(csv_file, delimiter=',', usecols=(3), skip_header=1)
    luts_conv2 = np.genfromtxt(csv_file, delimiter=',', usecols=(4), skip_header=1)
    luts_conv3 = np.genfromtxt(csv_file, delimiter=',', usecols=(5), skip_header=1)
    luts_fc1 = np.genfromtxt(csv_file, delimiter=',', usecols=(6), skip_header=1)
    luts_fc2 = np.genfromtxt(csv_file, delimiter=',', usecols=(7), skip_header=1)

    regs_conv1 = np.genfromtxt(csv_file, delimiter=',', usecols=(10), skip_header=1)
    regs_conv2 = np.genfromtxt(csv_file, delimiter=',', usecols=(11), skip_header=1)
    regs_conv3 = np.genfromtxt(csv_file, delimiter=',', usecols=(12), skip_header=1)
    regs_fc1 = np.genfromtxt(csv_file, delimiter=',', usecols=(13), skip_header=1)
    regs_fc2 = np.genfromtxt(csv_file, delimiter=',', usecols=(14), skip_header=1)

    lines = [
       Line2D([0], [0], color='slategray', lw=4),
       Line2D([0], [0], color='mediumseagreen', lw=4), 
       Line2D([0], [0], color='dodgerblue', lw=4),
       Line2D([0], [0], color='crimson', lw=4),
       Line2D([0], [0], color='gold', lw=4)]
    area_img, axes = plt.subplots(2,1, sharex=True, figsize=(6, 5))
    axes[0].bar(conf, luts_conv1 , width, color='slategray')
    axes[0].bar(conf, luts_conv2, width, bottom=luts_conv1, color='mediumseagreen')
    axes[0].bar(conf, luts_conv3, width, bottom=luts_conv1+luts_conv2, color='dodgerblue')
    axes[0].bar(conf, luts_fc1, width, bottom=luts_conv1+luts_conv2+luts_conv3, color='crimson')
    axes[0].bar(conf, luts_fc2, width, bottom=luts_conv1+luts_conv2+luts_conv3+luts_fc1, color='gold')
    axes[0].set_ylabel('Amount of required LUTs')
    axes[0].set_xlabel('#Approx. Configuration')
    axes[1].bar(conf, regs_conv1 , width, color='slategray')
    axes[1].bar(conf, regs_conv2, width, bottom=regs_conv1, color='mediumseagreen')
    axes[1].bar(conf, regs_conv3, width, bottom=regs_conv1+regs_conv2, color='dodgerblue')
    axes[1].bar(conf, regs_fc1, width, bottom=regs_conv1+regs_conv2+regs_conv3, color='crimson')
    axes[1].bar(conf, regs_fc2, width, bottom=regs_conv1+regs_conv2+regs_conv3+regs_fc1, color='gold')
    axes[1].set_ylabel('Amount of required FFs')
    axes[1].set_xlabel('#Approx. Configuration')
    area_img.legend(lines, ('Conv1', 'Conv2', 'Conv3', 'FC1', 'FC2'), frameon=False, loc='upper center', ncol=5)
    area_img.savefig(fpga_pdf, bbox_inches='tight', pad_inches=0)
    
def plot_power(csv_file, plot_pdf):
    width=0.5
    lines = [
       Line2D([0], [0], color='slategray', lw=4),
       Line2D([0], [0], color='mediumseagreen', lw=4), 
       Line2D([0], [0], color='dodgerblue', lw=4),
       Line2D([0], [0], color='crimson', lw=4),
       Line2D([0], [0], color='gold', lw=4)]
    conf = np.genfromtxt(csv_file, delimiter=',', usecols=(0), skip_header=1)
    error = np.genfromtxt(csv_file, delimiter=',', usecols=(1), skip_header=1)
    reward = np.genfromtxt(csv_file, delimiter=',', usecols=(2), skip_header=1)
    pwr_conv1 = np.genfromtxt(csv_file, delimiter=',', usecols=(17), skip_header=1)
    pwr_conv2 = np.genfromtxt(csv_file, delimiter=',', usecols=(18), skip_header=1)
    pwr_conv3 = np.genfromtxt(csv_file, delimiter=',', usecols=(19), skip_header=1)
    pwr_fc1 = np.genfromtxt(csv_file, delimiter=',', usecols=(20), skip_header=1)
    pwr_fc2 = np.genfromtxt(csv_file, delimiter=',', usecols=(21), skip_header=1)
    plt.figure(figsize=[8, 6])
    plt.bar(conf, pwr_conv1 , width, color='slategray')
    plt.bar(conf, pwr_conv2, width, bottom=pwr_conv1, color='mediumseagreen')
    plt.bar(conf, pwr_conv3, width, bottom=pwr_conv1+pwr_conv2, color='dodgerblue')
    plt.bar(conf, pwr_fc1, width, bottom=pwr_conv1+pwr_conv2+pwr_conv3, color='crimson')
    plt.bar(conf, pwr_fc2, width, bottom=pwr_conv1+pwr_conv2+pwr_conv3+pwr_fc1, color='gold')
    plt.ylabel('Power consumption (uW)')
    plt.xlabel('#Approx. Configuration')
    plt.xticks(np.arange(np.max(conf)+1))
    plt.legend(lines, ('Conv1', 'Conv2', 'Conv3', 'FC1', 'FC2'), frameon=False, loc='upper center', ncol=5, bbox_to_anchor=(0.2, 0.6, 0.5, 0.5))
    plt.savefig(plot_pdf, bbox_inches='tight', pad_inches=0)
    #plt.savefig(plot_pdf, pad_inches=0)

plot_hw_resources('16bits.csv', '16bits_pareto.pdf', '16bits_fpga.pdf')
plot_hw_resources('8bits.csv', '8bits_pareto.pdf', '8bits_fpga.pdf')
plot_power('16bits.csv', '16bits_power.pdf')
plot_power('8bits.csv', '8bits_power.pdf')
